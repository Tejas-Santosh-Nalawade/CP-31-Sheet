#include<bits/stdc++.h>
using namespace std;


using ll = long long;

void solve() {
	int intervalCount;
	cin >> intervalCount;

	vector<pair<int, int>> intervals(intervalCount);
	vector<int> leftEndpoints(intervalCount);
	vector<int> rightEndpoints(intervalCount);

	for (int i = 0; i < intervalCount; ++i) {
		cin >> intervals[i].first >> intervals[i].second;
		leftEndpoints[i] = intervals[i].first;
		rightEndpoints[i] = intervals[i].second;
	}

	sort(leftEndpoints.begin(), leftEndpoints.end());
	sort(rightEndpoints.begin(), rightEndpoints.end());

	int minimumRemovals = intervalCount - 1;

	for (auto [left, right] : intervals) {
		int leftOverlapCount = lower_bound(rightEndpoints.begin(), rightEndpoints.end(), left) - rightEndpoints.begin();
		int rightOverlapCount = max(0, intervalCount - static_cast<int>(upper_bound(leftEndpoints.begin(), leftEndpoints.end(), right) - leftEndpoints.begin()));
		minimumRemovals = min(minimumRemovals, leftOverlapCount + rightOverlapCount);
	}

	cout << minimumRemovals << "\n";
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
}