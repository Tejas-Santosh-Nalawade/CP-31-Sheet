#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		map<int, int> cnt;
		int mx = 0;
		for (auto &it : a) {
			if (it % k == 0) continue;
			++cnt[k - it % k];
			mx = max(mx, cnt[k - it % k]);
		}
		long long ans = 0;
		for (auto [key, value] : cnt) {
			if (value == mx) {
				ans = k * 1ll * (value - 1) + key + 1;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}