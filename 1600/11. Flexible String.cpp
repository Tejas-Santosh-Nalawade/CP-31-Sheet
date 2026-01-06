#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int tc;
		cin >> tc;
		while (tc--) {
				int n, k;
				cin >> n >> k;
				string a, b;
				cin >> a >> b;

				vector<int> id(26, -1);           
				vector<char> u;                    
				for (char c : a) {
						if (id[c - 'a'] == -1) {     
								id[c - 'a'] = (int)u.size();
								u.push_back(c);
						}
				}

				ll ans = 0;
				int uc = (int)u.size();        
				int bc = min(k, uc);           
				for (int bm = 0; bm < (1 << uc); ++bm) {
						if (__builtin_popcount((unsigned)bm) != bc) continue;

						ll cnt = 0;                 
						ll match = 0;                
						for (int i = 0; i < n; ++i) {
		
								if (a[i] == b[i] || (bm & (1 << id[a[i] - 'a']))) {
										++match;
								} else {
										
										cnt += match * (match + 1) / 2;
										match = 0;
								}
						}
						cnt += match * (match + 1) / 2; 
						ans = max(ans, cnt);
				}

				cout << ans << '\n';
		}
		return 0;
}