#include <bits/stdc++.h>

using namespace std;

void solve() {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
				cin >> arr[i];
		}

	int odd = 0, even = 1;
	bool cur = 0;
	long long ans = 0;

	for (int i = 0; i < n; i++) {
			if (arr[i] < 0) cur = 1 - cur;

			if (cur == 0) {
						ans += even;
						even++;
				} else {
						ans += odd;
						odd++;
				}
		}

		cout << 1LL * n * (n + 1) / 2 - ans << ' ' << ans << '\n';
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		solve();
}
