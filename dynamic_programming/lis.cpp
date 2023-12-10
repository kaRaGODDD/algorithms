#include <iostream>
#include <vector>
#include <algorithm>

#define FILE

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

#ifdef FILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long n;
	std::cin >> n;

	std::vector<long long> a(n);

	for (auto&& x : a) {
		std::cin >> x;
	}

	std::vector<long long> dp(n+1, LLONG_MAX);
	dp[0] = LLONG_MIN;
	std::size_t len = 0;

	for (std::size_t i = 0; i < a.size(); ++i) {
		auto idx = std::upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		if (dp[idx - 1] < a[i] && a[i] < dp[idx]) {
			dp[idx] = a[i];
		}
	}

	for (const auto& x : dp) {
		if (x != LLONG_MIN && x != LLONG_MAX) {
				++len;
		}
	}

	std::cout << len;
	return EXIT_SUCCESS;
}
