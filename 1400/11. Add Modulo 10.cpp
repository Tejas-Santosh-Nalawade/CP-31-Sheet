#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
				cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
				if (a[i] % 2 == 1) {
						a[i] += a[i] % 10; 
				}
		}
		if (count(a, a + n, a[0]) == n) { 
				cout << "YES\n";
				return;
		}

		for (int i = 0; i < n; i++) {
				if (a[i] % 10 == 0) { 
						cout << "NO\n";
						return;
				}
		}
		for (int i = 0; i < n; i++) {
				while (a[i] % 10 != 2) { 
						a[i] += a[i] % 10;
				}
				a[i] %= 20;
		}

		if (count(a, a + n, a[0]) == n) {
				cout << "YES\n";
				return;
		} else {
				cout << "NO\n";
		}
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int tt;
		cin >> tt;

		while (tt--) {
				solve();
		}
}
