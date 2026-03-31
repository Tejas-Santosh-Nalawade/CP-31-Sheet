#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

ll power(ll a, ll b) {
		ll r = 1;
		while (b) {
				if (b & 1) r = r * a % MOD; 
				a = a * a % MOD;         
				b >>= 1;                   
		}
		return r;                       
}

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
				ll n, m, k;
				cin >> n >> m >> k;

				ll S = 0; 
				for (int i = 0; i < m; ++i) {
						ll a, b, f;
						cin >> a >> b >> f;     
						S = (S + f) % MOD;    
				}

				ll T = n * (n - 1) / 2;           
				ll K2 = k * (k - 1) / 2;         

				ll invT = power(T % MOD, MOD - 2);   

				ll term1 = ((k % MOD) * (S % MOD)) % MOD * invT % MOD;
				ll term2 = (m % MOD) * (K2 % MOD) % MOD * invT % MOD * invT % MOD;  

				ll ans = (term1 + term2) % MOD;      
				cout << ans << '\n';
		}
}
