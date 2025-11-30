#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();

	vector<char> ans(n);

	ans[0] = s[0];

	for (int i = 1; i < n; i++) { 
		if (s[i] == ans[i - 1]) {
			for (char j = 'a'; j <= 'z'; j++) {
				if (j != s[i - 1]) {
					if (i < n - 1 && j != s[i + 1]) {
						ans[i] = j;
						break;
					} else if (i == n - 1) {
						ans[i] = j;
						break;
					}
				}
			}
		} else {
			ans[i] = s[i];
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i];
	cout << endl;

	return 0;
}
