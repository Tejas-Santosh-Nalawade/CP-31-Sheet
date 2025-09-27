#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = (1 << 30) - 1;
		for (int i = 0; i < n; ++i) { 
			int x; 
			cin >> x;
			if (x != i) {
				ans &= x;
			}
		}
		cout << ans << "\n";
	}
}