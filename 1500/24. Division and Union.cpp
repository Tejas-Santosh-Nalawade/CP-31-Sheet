#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;

		vector<vector<int>> a(n);
		for (int i = 0; i < n; i++) {
				int l, r;
				cin >> l >> r;
				a[i] = {l, r, i}; 
		}

		sort(a.begin(), a.end()); 

		vector<int> ans(n, 2); 
		int mx = a[0][1];      
		bool split_found = false; 

		for (int i = 0; i < n; i++) {
				if (a[i][0] > mx) {    
						split_found = true;  
						break;               
				}
				ans[a[i][2]] = 1;      
				mx = max(mx, a[i][1]);   
		}

		if (!split_found) {
				cout << "-1\n"; 
		} else {
				for (auto v : ans) cout << v << ' ';
				cout << '\n';
		}
}

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int tt;
		cin >> tt;
		while (tt--) {
				solve();
		}
        
		return 0;
}
