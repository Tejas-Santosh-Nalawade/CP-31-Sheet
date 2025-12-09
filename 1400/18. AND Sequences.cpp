#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int MOD = 1000000007;
int fact[N + 1];

void solve() {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
				cin >> a[i];
		}

		int totalAnd = a[0];
		for (int i = 1; i < n; i++) {
				totalAnd &= a[i];
		}

		int countAnd = count(a, a + n, totalAnd);
		if (countAnd <= 1) {
				cout << 0 << "\n";
				return;
		}

		cout << 1LL * countAnd * (countAnd - 1) % MOD * fact[n - 2] % MOD << '\n';
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		fact[0] = 1;
		for (int i = 1; i <= N; i++) {
				fact[i] = (1LL * fact[i - 1] * i) % MOD;
		}

		int tt;
		cin >> tt;
		while (tt--) {
				solve();
		}
}
