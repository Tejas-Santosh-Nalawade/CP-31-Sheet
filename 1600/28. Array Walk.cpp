#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int tc;
		cin >> tc;
		while (tc--) {
				int n, k, Z;
				cin >> n >> k >> Z;

				vector<int> a(n);
				for (auto &x : a) cin >> x;

				ll ans = 0;
				for (int z = 0; z <= Z && 2 * z <= k; ++z) {
						int r = k - 2 * z;  
						ll base = accumulate(a.begin(), a.begin() + r + 1, 0LL);  
						int bestPair = 0;
						for (int i = 1; i <= min(r + 1, n - 1); ++i) {
								bestPair = max(bestPair, a[i] + a[i - 1]);
						}
						ll res = base + 1LL * z * bestPair;
						ans = max(ans, res);
				}

				cout << ans << '\n';
		}

		return 0;
}
