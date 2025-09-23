#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	ll l, r;
	cin >> l >> r;
	vector<ll> ans; 

	for (int i = 1; i <= n; i++) {
		ll temp = ((l + i - 1) / i) * i;
		ans.push_back(temp); 

		if (temp > r) {
			cout << "NO" << "\n";
			return;
		}
	}

	cout << "YES" << "\n";
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << "\n";
}

int main() {
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}
