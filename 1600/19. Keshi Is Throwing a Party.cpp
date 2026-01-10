#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v; 

bool check(int x) {
		int c = 0;
		for (int i = 0; i < n; i++) {
				if (v[i].second >= c && v[i].first >= x - c - 1) {
						c++;
				}
		}
		return c >= x;
}

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int tc;
		cin >> tc;
		while (tc--) {
				cin >> n;
				v.resize(n);
				for (auto &p : v) cin >> p.first >> p.second; 

				int l = 1, r = n, best = 1; 
				while (l <= r) {
						int mid = (l + r) / 2;
						if (check(mid)) {
								best = mid; 
								l = mid + 1;
						} else {
								r = mid - 1;
						}
				}

				cout << best << '\n';
		}

		return 0;
}