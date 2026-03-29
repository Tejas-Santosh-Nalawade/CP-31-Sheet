#include <bits/stdc++.h>
using namespace std;

void solve() {
	int numPairs;
	cin >> numPairs;
	vector<int> startIndices(numPairs), endIndices(numPairs);
	vector<string> firstNames(numPairs), secondNames(numPairs);
	vector<string> allNames;

	for (int i = 0; i < numPairs; ++i) {
		string firstName, secondName;
		cin >> firstName >> secondName;
		allNames.push_back(firstName);
		allNames.push_back(secondName);
		firstNames[i] = firstName;
		secondNames[i] = secondName;
	}

	sort(allNames.begin(), allNames.end());
	allNames.erase(unique(allNames.begin(), allNames.end()), allNames.end());

	for (int i = 0; i < numPairs; ++i) {
		startIndices[i] = lower_bound(allNames.begin(), allNames.end(), firstNames[i]) - allNames.begin();
		endIndices[i] = lower_bound(allNames.begin(), allNames.end(), secondNames[i]) - allNames.begin();
	}

	vector<vector<int>> dp(1 << numPairs, vector<int>(numPairs, 0));

	for (int i = 0; i < numPairs; ++i) {
		dp[1 << i][i] = 1;
	}

	for (int mask = 0; mask < (1 << numPairs); ++mask) {
		for (int last = 0; last < numPairs; ++last) {
			if (!dp[mask][last]) continue;
			for (int i = 0; i < numPairs; ++i) {
				if (mask & (1 << i)) continue;
				if (startIndices[last] == startIndices[i] || endIndices[last] == endIndices[i]) {
					dp[mask | (1 << i)][i] |= dp[mask][last];
				}
			}
		}
	}

	int maxDistinctPairs = 0;

	for (int mask = 0; mask < (1 << numPairs); ++mask) {
		for (int i = 0; i < numPairs; ++i) {
			if (dp[mask][i]) {
				maxDistinctPairs = max(maxDistinctPairs, __builtin_popcount(mask));
			}
		}
	}

	cout << numPairs - maxDistinctPairs << "\n";
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) {
		solve();
	}
	return 0;
}