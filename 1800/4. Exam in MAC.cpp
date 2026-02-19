#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solveTestCase() {
	int arraySize, cValue;
	cin >> arraySize >> cValue;

	vector<int> elements(arraySize);
	for (int &element : elements) {
		cin >> element;
	}

	int oddCount = 0, evenCount = 0;
	ll result = static_cast<ll>(cValue + 1) * (cValue + 2) / 2;

	for (const int &element : elements) {
		result -= element / 2 + 1;
		result -= cValue - element + 1;

		if (element % 2 == 0) {
			evenCount++;
		} else {
			oddCount++;
		}
	}

	result += static_cast<ll>(evenCount) * (evenCount + 1) / 2;
	result += static_cast<ll>(oddCount) * (oddCount + 1) / 2;

	cout << result << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int testCases;
	cin >> testCases;
	while (testCases--) {
		solveTestCase();
	}

	return 0;
}