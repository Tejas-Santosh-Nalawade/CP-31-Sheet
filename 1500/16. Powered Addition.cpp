#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i; 

	int mx = 0; 
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) { 
			mx = max(mx, a[i - 1] - a[i]); 
			a[i] = a[i - 1];
		}
	}

	int ans = 0;
	if (mx > 0)
		ans = static_cast<int>(log2(mx)) + 1; 

	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt;
	cin >> tt; 
	while (tt--) {
		solve();
	}

	return 0;
}
