#include <bits/stdc++.h>
using namespace std;

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		string ans(k, 'z');

		for (int len = 1; len <= n; ++len) {
				string t = s.substr(0, len); 

			
				while ((int)t.size() < k) t = t + t;
				t = t.substr(0, k);
				ans = min(ans, t);
		}

		cout << ans << '\n';
		return 0;
}