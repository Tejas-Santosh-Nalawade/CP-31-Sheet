#include <bits/stdc++.h>
using namespace std;

void solve() {
		long long n, x, y;
		cin >> n >> x >> y;
		long long a[n];
		for (int i = 0; i < n; i++) {
				cin >> a[i];
		}

		int numOdds = 0;
		for (int i = 0; i < n; i++) {
				if (a[i] % 2 == 1) numOdds++;
		}

		int aliceStart = x % 2;
		int bobStart = 1 - aliceStart;

		int aliceEnd, bobEnd;
		if (numOdds % 2 == 0) {
				aliceEnd = aliceStart;
				bobEnd = bobStart;
		} else {
				aliceEnd = 1 - aliceStart;
				bobEnd = 1 - bobStart;
		}

		if (y % 2 == aliceEnd) {
				cout << "Alice\n";
		} else {
				cout << "Bob\n";
		}
}

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int tt;
		cin >> tt;
		while (tt--) {
				solve();
		}
}
