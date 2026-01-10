#include <bits/stdc++.h>
using namespace std;

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		const vector<string> tiles = {"abc", "acb", "bac", "bca", "cab", "cba"};

		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector<vector<int>> pref(6, vector<int>(n, 0));
		for (int j = 0; j < 6; ++j) {
				for (int i = 0; i < n; ++i) {
						if (i) pref[j][i] = pref[j][i - 1]; 
						if (s[i] != tiles[j][i % 3]) ++pref[j][i]; 
				}
		}

		while (q--) {
				int l, r;
				cin >> l >> r;
				--l, --r; 

				int best = r - l + 1;
				for (int j = 0; j < 6; ++j) {
						int mismatches = pref[j][r] - (l ? pref[j][l - 1] : 0);
						best = min(best, mismatches);
				}
				cout << best << '\n';
		}

		return 0;
}
