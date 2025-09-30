#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;

	vector<int> first_pos(51, n + 1);

	for (int i = 1; i <= n; i++) { 
		int color;
		cin >> color;
		if (first_pos[color] == n + 1) {
			first_pos[color] = i;
		}
	}

	while (q--) { 
        int color;
		cin >> color;
		int ans = first_pos[color];

		for (int i = 1; i <= 50; i++) {
			if (first_pos[i] < ans) {
				first_pos[i]++;
			}
		}

		first_pos[color] = 1;

		cout << ans << " ";
	}

	cout << endl;
}
