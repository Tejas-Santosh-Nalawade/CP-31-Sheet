#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> nearestEnemy(n + 1, 0);

		for (int i = 0; i < m; i++) {
				int a, b;
				cin >> a >> b;
				if (a > b) swap(a, b);             
				nearestEnemy[b] = max(nearestEnemy[b], a); 
		}

		vector<int> maxLeft(n + 1);

		maxLeft[1] = 1; 

		long long ans = 1; 

		for (int i = 2; i <= n; i++) {
				maxLeft[i] = max(maxLeft[i - 1], nearestEnemy[i] + 1);
				ans += i - maxLeft[i] + 1;
		}

		cout << ans << '\n';
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> tt;
		while (tt--) {
				solve();
		}
}