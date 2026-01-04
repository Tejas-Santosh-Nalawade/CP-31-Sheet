#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);

		int tc;
		cin >> tc;
		while (tc--) {
				int n;
				cin >> n;
				vector<int> v(n);

				bool hasNonZero = false; 
				for (auto &x : v) {
						cin >> x;
						hasNonZero |= (x != 0);
				}
				if (!hasNonZero) {
						cout << "No\n";
						continue;
				}
				cout << "Yes\n";

				vector<int> pos, neg;
				for (auto &x : v) {
						if (x >= 0)
								pos.push_back(x); 
						else
								neg.push_back(x);
				}

				vector<int> ans(n);
				ll psum = 0; 
				for (int i = 0; i < n; i++) {
						if (psum <= 0 && !pos.empty()) {
								ans[i] = pos.back();
								pos.pop_back();
						} else {
								ans[i] = neg.back();
								neg.pop_back();
						}
						psum += ans[i];
				}

				for (auto &x : ans) cout << x << ' ';
				cout << '\n';
		}

		return 0;
}
