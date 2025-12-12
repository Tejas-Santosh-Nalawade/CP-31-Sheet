#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;

		int b[n];
		for (int i = 0; i < n; i++) {
				cin >> b[i];
		}

map<int, long long> poss;

	for (int i = 0; i < n; i++) {
			poss[i - b[i]] += b[i];
	}

	long long ans = 0;
	for (auto [key, sum] : poss) {
			ans = max(ans, sum);
		}

		cout << ans << '\n';
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		solve();
}

