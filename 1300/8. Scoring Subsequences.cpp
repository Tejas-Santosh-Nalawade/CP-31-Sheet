#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt; 

	while (tt--) {
		int n;
		cin >> n; 

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<int> res; 
		for (int i = 0; i < n; i++) {
			int l = 1, r = i + 1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (a[i - m + 1] >= m) {
					l = m + 1; 
				} else {
					r = m - 1; 
				}
			}
			res.push_back(r);
		}

		for (auto i : res) {
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}

