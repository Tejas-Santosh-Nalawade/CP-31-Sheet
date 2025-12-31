#include <bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	vector<int> diff(n + 1, 0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;         
		diff[l]++;         
		diff[r + 1]--;    
	}
	for (int i = 1; i <= n; i++)
		diff[i] += diff[i - 1];
	sort(diff.rbegin(), diff.rend());
	sort(a.rbegin(), a.rend());

	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] * diff[i];
	cout << ans << '\n';

	return 0;
}