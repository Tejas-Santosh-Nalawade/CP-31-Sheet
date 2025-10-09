#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;

	while (tt--) {
		int n;
		cin >> n;

		vector<int> v(n); 
		for (int i = 0; i < n; i++)
			cin >> v[i]; 

		map<int, int> cnt; 
		for (int i = 0; i < n; i++)
			cnt[v[i]]++; 

		int ans = 0; 
		for (auto &[ele, fre] : cnt) {
			ans += max(0, cnt[ele] - cnt[ele - 1]);
		}

		cout << ans << "\n"; 
	}

	return 0;
}

