#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt; 
	while (tt--) {
		int n;
		cin >> n; 
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++) { 
			cin >> a[i]; 
		}

		vector<int> previous_different(n, -1);
		int prv = -1;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1])
				prv = i - 1;
			previous_different[i] = prv;
		}

		int q;
		cin >> q;
		while (q--) {
			int l, r;
			cin >> l >> r;
			if (previous_different[r - 1] >= l - 1) {
				cout << r << " " << previous_different[r - 1] + 1 << endl;
			} else {
				cout << -1 << " " << -1 << endl;
			}
		}
		cout << endl;
	}
}

