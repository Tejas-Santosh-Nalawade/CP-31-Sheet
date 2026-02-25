#include <bits/stdc++.h>
using namespace std;


using namespace std;

void solve() {
	int arraySize;
	cin >> arraySize;
	vector<int> permutation(arraySize);
	for (int i = 0; i < arraySize; i++) {
		cin >> permutation[i];
		permutation[i]--;
	}

	int componentIndex = 1, totalCycles = 0;
	vector<int> component(arraySize, 0);

	for (int i = 0; i < arraySize; i++) {
		if (component[i]) continue;

		int current = i;
		while (component[current] == 0) {
			component[current] = componentIndex;
			current = permutation[current];
			totalCycles++;
		}
		componentIndex++;
		totalCycles--;
	}

	for (int i = 0; i < arraySize - 1; i++) {
		if (component[i] == component[i + 1]) {
			cout << totalCycles - 1 << '\n';
			return;
		}
	}
	cout << totalCycles + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int testCases;
	cin >> testCases;
	while (testCases--) solve();

	return 0;
}