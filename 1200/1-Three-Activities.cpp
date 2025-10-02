#include <bits/stdc++.h>

using namespace std;

vector<int> findMax3(vector<int> &arr) {

	vector<pair<int, int>> tmp(arr.size());

	for (int i = 0; i < tmp.size(); i++) {
		tmp[i].first = arr[i];
		tmp[i].second = i;
	}

	sort(tmp.rbegin(), tmp.rend());

	vector<int> ans(3);

	for (int i = 0; i < 3; i++)
		ans[i] = tmp[i].second;

	return ans;
}

int main() {
	int tt;
	cin >> tt; 
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n), c(n);

		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i]; 
		for (int i = 0; i < n; i++)
			cin >> c[i]; 

		vector<int> maxa = findMax3(a); 
		vector<int> maxb = findMax3(b);
		vector<int> maxc = findMax3(c);

		int ans = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					int x = maxa[i], y = maxb[j], z = maxc[k];
					if ((x == y) or (y == z) or (z == x))
						continue;
					ans = max(ans, a[x] + b[y] + c[z]); // O(1)
				}
			}
		}

		cout << ans << endl; 
	}
}
