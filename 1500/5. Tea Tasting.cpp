#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
		int n;
		cin >> n;
	vector<int> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];

		vector<int> pr(n + 1, 0);
	for (int i = 1; i <= n; i++) pr[i] = pr[i - 1] + b[i];
		vector<int> cnt(n + 2, 0), ans(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			int x = a[i] + pr[i - 1];
			int j = upper_bound(pr.begin(), pr.end(), x) - pr.begin();
			if (j <= n) {
					ans[j] += x - pr[j - 1];
			}
				cnt[i]++;
				cnt[j]--;
		}
		for (int i = 1; i <= n; i++) {
				cnt[i] += cnt[i - 1]; 
				ans[i] += cnt[i] * b[i];
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << '\n';
}

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		int tt;
		cin >> tt;
		while (tt--) {
				solve();
		}
		return 0;
}

