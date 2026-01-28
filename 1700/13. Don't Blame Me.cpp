#include<bits/stdc++.h>

using namespace std;

const int MODULO = 1e9 + 7;

void solve() {
	int arraySize, targetPopcount;
	cin >> arraySize >> targetPopcount;
	vector<int> numbers(arraySize + 1);
	vector<vector<int>> dp(arraySize + 1, vector<int>(1 << 6, 0));

	for (int i = 1; i <= arraySize; ++i) {
		cin >> numbers[i];
		for (int mask = 0; mask < (1 << 6); ++mask) {
			dp[i][mask] = (dp[i][mask] + dp[i - 1][mask]) % MODULO;
			int combinedMask = mask & numbers[i];
			dp[i][combinedMask] = (dp[i][combinedMask] + dp[i - 1][mask]) % MODULO;
		}
		dp[i][numbers[i]] = (dp[i][numbers[i]] + 1) % MODULO;
	}

	int result = 0;
	for (int mask = 0; mask < (1 << 6); ++mask) {
		if (__builtin_popcount(mask) == targetPopcount) {
			result = (result + dp[arraySize][mask]) % MODULO;
		}
	}

	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCases;
	cin >> testCases;

	while (testCases--) {
		solve();
	}

	return 0;
}