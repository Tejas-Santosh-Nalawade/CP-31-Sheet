#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<vector<int>> dp(n + 1, vector<int>(2, 0));
		dp[n][0] = 0;
		dp[n][1] = 0;
		dp[n - 1][0] = 0;             
		dp[n - 1][1] = a[n - 1];          

		for (int i = n - 2; i >= 0; i--) {
			dp[i][0] = min(dp[i + 1][1], dp[i + 2][1]);
			dp[i][1] = min(
				dp[i + 1][0] + a[i],                
				dp[i + 2][0] + a[i] + a[i + 1]      
			);
		}

		cout << dp[0][1] << '\n';
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
