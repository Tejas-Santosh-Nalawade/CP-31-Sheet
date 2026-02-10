#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int numberOfCheckpoints, totalDistance, maxRemovals;
	cin >> numberOfCheckpoints >> totalDistance >> maxRemovals;

	vector<int> distances(numberOfCheckpoints), costs(numberOfCheckpoints);

	for (int i = 0; i < numberOfCheckpoints; i++) {
		cin >> distances[i];
	}

	for (int i = 0; i < numberOfCheckpoints; i++) {
		cin >> costs[i];
	}

	vector<vector<int>> previousCost(maxRemovals + 1, vector<int>(numberOfCheckpoints));

	for (int removals = 0; removals <= maxRemovals; removals++) {
		for (int previousCheckpoint = 0; previousCheckpoint < numberOfCheckpoints; previousCheckpoint++) {
			previousCost[removals][previousCheckpoint] = (totalDistance - distances[previousCheckpoint]) * costs[previousCheckpoint];
		}
	}

	for (int i = numberOfCheckpoints - 1; i >= 1; i--) {
		vector<vector<int>> currentCost(maxRemovals + 1, vector<int>(numberOfCheckpoints));
		for (int previousCheckpoint = i - 1; previousCheckpoint >= 0; previousCheckpoint--) {
			for (int removals = 0; removals <= maxRemovals; removals++) {
				int takeCost = ((distances[i] - distances[previousCheckpoint]) * costs[previousCheckpoint]) + previousCost[removals][i];

				int notTakeCost = INT_MAX;
				if (removals > 0) {
					notTakeCost = previousCost[removals - 1][previousCheckpoint];
				}

				currentCost[removals][previousCheckpoint] = min(takeCost, notTakeCost);
			}
		}
		previousCost = currentCost;
	}

	cout << previousCost[maxRemovals][0] << endl;

	return 0;
}