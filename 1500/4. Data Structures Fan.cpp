#include <bits/stdc++.h>

using namespace std;

void solve() {
		int n;
		cin >> n;
		vector<int> a(n + 1); 
		for (int i = 1; i <= n; i++) cin >> a[i];

		string s;
		cin >> s;
		s = "*" + s; 

		int xr0 = 0, xr1 = 0; 
		for (int i = 1; i <= n; i++) {
				if (s[i] == '1')
						xr1 ^= a[i];
				else
						xr0 ^= a[i];
		}

		vector<int> prXor(n + 1, 0);
		for (int i = 1; i <= n; i++) {
				prXor[i] = prXor[i - 1] ^ a[i];
		}

		int q;
		cin >> q;
		while (q--) {
				int tp;
				cin >> tp;
				if (tp == 1) { 
						int l, r;
						cin >> l >> r;
						int xrlr = prXor[r] ^ prXor[l - 1];
						xr0 ^= xrlr;
						xr1 ^= xrlr;
				} else { 
						int g;
						cin >> g;
						if (g == 0)
								cout << xr0 << ' ';
						else
								cout << xr1 << ' ';
				}
		}
		cout << '\n';
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
