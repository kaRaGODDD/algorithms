#include <iostream>
#include <vector>

constexpr long long MOD = 1e9 + 7;

long long count_ways(int n, int m) {

    std::vector<long long> dp(m);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[j] = (dp[j] + dp[j-1]) % MOD; 
        }
    }

    return dp[m-1];
}

int main() {
    int n{}, m{};
    std::cin >> n >> m;

    auto ways = count_ways(n, m);

    std::cout << ways; 

    return 0;
}

