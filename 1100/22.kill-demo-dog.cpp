#include <bits/stdc++.h>
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
int solve() {
	ll n;
	cin >> n;
	ll ans = ((((n * (n + 1)) % mod) * (4 * n - 1)) % mod * 337) % mod;

	cout << ans << "\n";
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
}
