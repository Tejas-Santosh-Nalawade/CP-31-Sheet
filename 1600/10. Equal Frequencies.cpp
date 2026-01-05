#include <bits/stdc++.h>
using namespace std;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);

		int tc;
		cin >> tc;
		while (tc--) {
				int n;
				cin >> n;
				string s;
				cin >> s;

				vector<pair<int, char>> freq(26);
				for (int i = 0; i < 26; i++) freq[i].second = 'a' + i; 
				for (char c : s) freq[c - 'a'].first++; 
				sort(freq.rbegin(), freq.rend()); 
				int best_k = 1, changes = n;
				for (int k = 1; k <= 26; k++) {
						if (n % k) continue; 
						int unchanged = 0;
						for (int i = 0; i < k; i++) unchanged += min(freq[i].first, n / k);
						if (n - unchanged < changes) {
								best_k = k;
								changes = n - unchanged;
						}
				}
				map<char, int> mp;
				for (int i = 0; i < best_k; i++) mp[freq[i].second] = n / best_k;

				string ans(n, ' ');
				for (int i = 0; i < n; i++) {
						if (mp[s[i]] > 0) {
								ans[i] = s[i];
								mp[s[i]]--;
						}
				}

				for (int i = 0; i < n; i++) {
						if (ans[i] != ' ') continue; 
						while (!mp.empty() && (*mp.begin()).second == 0) mp.erase(mp.begin()); 
						char ch = (*mp.begin()).first; 
						ans[i] = ch;
						mp[ch]--;
				}

				cout << changes << "\n" << ans << "\n";
		}

		return 0;
}