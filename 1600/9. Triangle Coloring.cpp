#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m) + m) % m; }
ll sub(ll a, ll b, ll m = MOD) { return ((a % m) - (b % m) + m) % m; }
ll mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
ll modexp(ll a, ll e, ll m = MOD) {
		a %= m;
		ll r = 1;
		while (e) {
				if (e & 1) r = mul(r, a, m); 
				a = mul(a, a, m); 
				e >>= 1;
		}
		return r;
}
ll inv(ll a, ll m = MOD) { return modexp(a, m - 2, m); }

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int n;
		cin >> n;
		int T = n / 3;
		int K = n / 6;

		ll ans = 1;
		for (int i = 1; i <= K; ++i) {
				ans = mul(ans, T - i + 1); 
				ans = mul(ans, inv(i));    
		}

		vector<int> e(3); 
		for (int i = 0; i < n; ++i) {
				int w;
				cin >> w;
				e[i % 3] = w; 

				if (i % 3 == 2) {
						sort(e.begin(), e.end());
						int m = 1;          
						if (e[0] == e[1]) ++m; 
						if (e[0] == e[2]) ++m; 
						ans = mul(ans, m);
				}
		}
		cout << ans;
		return 0;
}
