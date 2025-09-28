#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt; 
	while (tt--) {
		int n;
		cin >> n;
		vector<int> v(n); 
		for (int i = 0; i < n; i++) {
			cin >> v[i]; 
		}

		int ans = 0; 
		int i = n - 1;
		while (i >= 0 && v[i] == v[n - 1]) {
			i--;
		}
		if (i == -1) {
			cout << 0 << endl;
			continue;
		}
		while (i >= 0) {
			i -= (n - 1 - i);
			ans++;
			while (i >= 0 && v[i] == v[n - 1]) {
				i--;
			}
		}

		cout << ans << "\n";
	}
}
