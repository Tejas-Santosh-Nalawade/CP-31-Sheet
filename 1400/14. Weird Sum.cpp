#include <bits/stdc++.h>
using namespace std;

const int MAX_COLOUR = 100000;

long long calculateSumOfAllPairs(vector<int>& v) {
		sort(v.begin(), v.end(), greater<>());
		int n = v.size();

		long long sum = 0;

		for (int i = 0, j = n - 1; i < n; i++, j -= 2) {
				sum += 1LL * j * v[i];
		}

		return sum;
}

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int n, m;
		cin >> n >> m;

	int a[n][m];
	for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
					cin >> a[i][j];
					a[i][j]--;
			}
	}

	vector<vector<int>> x(MAX_COLOUR);
	vector<vector<int>> y(MAX_COLOUR);

	for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
					x[a[i][j]].push_back(i);
					y[a[i][j]].push_back(j);
			}
	}

	long long ans = 0;

	for (int colour = 0; colour < MAX_COLOUR; colour++) {
			ans += calculateSumOfAllPairs(x[colour]);
			ans += calculateSumOfAllPairs(y[colour]);
	}

	cout << ans;
}