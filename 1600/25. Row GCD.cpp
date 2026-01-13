#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);

		ll n, m;
		cin >> n >> m;

		vector<ll> a(n);
		for (ll i = 0; i < n; i++) cin >> a[i];

		ll g = 0;
		for (ll i = 1; i < n; i++) g = std::gcd(g, a[i] - a[0]);

		for (ll i = 0; i < m; i++) {
			ll x;
			cin >> x;
			cout << std::gcd(x + a[0], g) << " ";
		}

		return 0;
}