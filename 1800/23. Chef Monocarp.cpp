#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

void solve() {
	int numElements;
	scanf("%d", &numElements);
	vector<int> elements(numElements);
	for (int i = 0; i < numElements; i++) {
		scanf("%d", &elements[i]);
		--elements[i];
	}
	sort(elements.begin(), elements.end());
	vector<vector<int>> dp(numElements + 1, vector<int>(2 * numElements, INF));
	dp[0][0] = 0;
	for (int i = 0; i <= numElements; i++) {
		for (int j = 0; j < 2 * numElements - 1; j++) {
			if (dp[i][j] < INF) {
				if (i < numElements) {
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(elements[i] - j));
				}
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			}
		}
	}

	printf("%d\n", dp[numElements][2 * numElements - 1]);
}

int main() {
	int testCases;
	scanf("%d", &testCases);
	for (int i = 0; i < testCases; i++) {
		solve();
	}
}
