#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int n;
vector<int> x, t;
ld best; 
bool check(ld T) {
	ld L = 0, R = 1e8; 
	for (int i = 0; i < n; i++) {
		ld reach = max(T - (ld)t[i], (ld)0);
		ld l = (ld)x[i] - reach;
		ld r = (ld)x[i] + reach;

		L = max(L, l);
		R = min(R, r);

		if (R < L) return false;
	}
	best = (L + R) / 2;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;

		x.resize(n);
		for (auto &xi : x) cin >> xi;

		t.resize(n);
		for (auto &ti : t) cin >> ti;
.
		ld l = 0, r = 1e9; 
		for (int it = 0; it <= 60; it++) { 
			ld mid = (l + r) / 2;
			if (check(mid)) {
				r = mid; 
			} else {
				l = mid; 
			}
		}

		cout << setprecision(16) << best << "\n";
	}

	return 0;
}

