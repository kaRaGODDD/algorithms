#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#define FILE

constexpr long long MOD = 1e9 + 7;

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

#ifdef FILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long n;
	std::cin >> n;

	std::vector<long long> a(n+1, 0);

	if (n == 1) {
		std::cout << 1;
	}
	else {

		a[0] = 1;
		a[1] = 1;

		for (int i = 2; i <= n; ++i) {
			a[i] = (a[i - 1] + a[i - 2]) % MOD;
		}

		std::cout << a[n];
	}
	return EXIT_SUCCESS;
}
