#include <iostream>
#include <vector>

#define FILE

const long long MOD = 1e9 + 7;

//passing 12 of 15 tests error : MLE for big n and m

int main() {

#ifdef FILE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long n{}, m{};
    std::cin >> n >> m;
    std::vector<std::vector<long long>> dp(n+1,std::vector<long long>(m+1,0));

    for(std::size_t i = 0; i<=n; ++i) {
        dp[i][1] = 1;
    }

    for(std::size_t j = 0; j <= m; ++j) {
        dp[1][j] = 1;
    }

    for(std::size_t i = 2; i <= n; ++i) {
        for(std::size_t j = 2; j <= m; ++j) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    std::cout << "\n\n" << dp[n][m];

    return EXIT_SUCCESS;
}

