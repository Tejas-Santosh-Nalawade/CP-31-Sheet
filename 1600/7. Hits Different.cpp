#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);

		const int RC = 2023;
		const int N_max = RC * (RC + 1) / 2;

		vector<ll> dp1(N_max, 0), dp2(N_max, 0);

	dp1[0] = dp2[0] = 1;

	ll idx = 1;
		for (int rc = 1; rc < RC; rc++) {
				int prev_row = idx - rc;
				for (int i = 0; i <= rc; i++) {
						ll cur = (ll)(idx + 1) * (idx + 1);

				dp1[idx] = cur + ((i > 0) ? dp1[prev_row + i - 1] : 0LL);

						dp2[idx] = dp1[idx] + ((i < rc) ? dp2[prev_row + i] : 0LL);

						idx++;
				}
		}

		int tc;
		cin >> tc;
		while (tc--) {
				int n;
				cin >> n;
				--n;
				cout << dp2[n] << '\n';
		}

		return 0;
}
