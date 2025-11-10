#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n; 
	int a[n];
	for (int i = 0; i < n; i++) { 
		cin >> a[i];
	}
	long long res = 0; 
	vector<int> v; 
	for (int i = 0; i < n; i++) { 
		if (a[i] >= i + 1) {
			continue; 
		}
		res += (long long)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
		v.push_back(i + 1);
	}
	cout << res << '\n'; 
}

int main() {
	int tt;
	cin >> tt;
	for (int i = 1; i <= tt; i++)
		solve();
	return 0;
}
