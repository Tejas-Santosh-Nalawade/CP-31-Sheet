#include <bits/stdc++.h>
using namespace std;

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int tc;
		cin >> tc;
		while (tc--) {
				int n;
				cin >> n;

				vector<int> dp(n + 1, 0); 
				dp[0] = 1;

				for (int i = 1; i <= n; ++i) {
						int x;
						cin >> x;
						if (dp[i - 1] && i + x <= n) dp[i + x] = 1;
						if (i - x - 1 >= 0) dp[i] = dp[i] || dp[i - x - 1];
				}

				cout << (dp[n] ? "YES\n" : "NO\n");
		}
		return 0;
}
