#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		unordered_map<int, int> mp;
		mp[0]++;

		int pref = 0; 
		for (int i = 0; i < n; i++) {
			pref += (s[i] - '0');
			mp[pref - (i + 1)]++;
		}

		ll ans = 0;
		for (auto &[key, cnt] : mp) {
			ans += (ll)cnt * (cnt - 1) / 2;
		}

		cout << ans << "\n";
	}

	return 0;
}