#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;
		while (t--) {
				int n;
				cin >> n;
				vector<int> a(n);
				for (auto &i : a)
						cin >> i;

				int sum = accumulate(a.begin(), a.end(), 0LL); 
				int rem = sum / 2; 
				int ans = sum - rem; 

				sort(a.rbegin(), a.rend());
				for (auto x : a) {
						if (rem <= 0)
								break; 
						rem -= x; 
						ans++; 
				}

				cout << ans << '\n';
		}

		return 0;
}