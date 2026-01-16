#include <bits/stdc++.h>
using namespace std;

int main() {
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		if (n > m) {
				cout << 0;
				return 0;
		}

		int ans = 1;
		for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
						ans = (ans * (abs(a[j] - a[i]) % m)) % m;
				}
		}

		cout << ans;
		return 0;
}
