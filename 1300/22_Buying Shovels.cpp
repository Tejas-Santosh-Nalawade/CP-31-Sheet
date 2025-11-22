#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;

	for (int tt = 0; tt < test; tt++) {
		int n, k;
		cin >> n >> k;

		int ans = n;

		for (int j = 1; j * j <= n; j++) {
			if (n % j == 0) {
				if (j <= k) {
					ans = min(ans, n / j);
				}

				if (n / j <= k) {
					ans = min(ans, j);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}