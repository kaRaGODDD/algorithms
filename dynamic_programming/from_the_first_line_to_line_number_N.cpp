#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

#define FILE


int main() {

#ifdef FILE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n{},m{};
    std::cin >> n >> m;

    std::vector<std::vector<long long>> mtx(n,std::vector<long long>(m));
    
    for(auto&& x : mtx) {
        for(auto&& y : x) {
            std::cin >> y; 
        }
    }

    std::vector<std::vector<long long>> dp(n,std::vector<long long>(m,0));
    dp[0] = mtx[0];

    long long left_element{},right_element,up_element{};
    
    for(std::size_t i = 1; i < n; ++i) {
        for(std::size_t j = 0; j < m; ++j) {
            if (j - 1 >= 0) {
                left_element = dp[i-1][j-1];
            } else {
                left_element = LLONG_MAX;
            }
            if (j + 1 < m) {
                right_element = dp[i-1][j+1];
            } else {
                right_element = LLONG_MAX;
            }
            up_element = dp[i-1][j];
            dp[i][j] = mtx[i][j] + std::min(up_element,std::min(right_element,left_element));
        }
    }
    
    std::cout << *std::min_element(dp.back().begin(),dp.back().end());

    return EXIT_SUCCESS;
}
