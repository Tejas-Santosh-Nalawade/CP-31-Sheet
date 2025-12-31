#include <bits/stdc++.h>
using namespace std;

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n;
		cin >> n;
		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++) {
				cin >> l[i] >> r[i];
		}

		vector<pair<int, int>> vec; 
		for (int i = 0; i < n; i++) {
				vec.push_back({l[i], 1});    
				vec.push_back({r[i] + 1, -1});
		}

		sort(vec.begin(), vec.end()); 

		int s = 0; 
		for (auto it : vec) {
				s += it.second;     
				if (s > 2) {         
						cout << "NO\n";
						return 0;
				}
		}

		cout << "YES\n"; 
		return 0;
}