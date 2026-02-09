#include<bits/stdc++.h>

using namespace std;

long long computeGCD(long long a, long long b) {
	return b == 0 ? a : computeGCD(b, a % b);
}

int determineCycleShift(const string &s) {
	int length = s.size();
	for (int i = 1; i <= length; ++i) {
		bool isShiftValid = true;
		for (int j = 0; j < length; ++j) {
			if (s[j] != s[(j + i) % length]) {
				isShiftValid = false;
				break;
			}
		}
		if (isShiftValid) return i;
	}
	return length;
}

void solveTestCase() {
	int n;
	cin >> n;

	string sequence;
	cin >> sequence;

	vector<int> permutation(n);
	for (int i = 0; i < n; ++i) {
		cin >> permutation[i];
		--permutation[i];
	}

	vector<bool> visited(n, false);
	long long result = 1;

	for (int i = 0; i < n; ++i) {
		if (visited[i]) continue;

		string cycleSubstring;
		int currentIndex = i;


		while (!visited[currentIndex]) {
			cycleSubstring += sequence[currentIndex];
			visited[currentIndex] = true;
			currentIndex = permutation[currentIndex];
		}

		int cycleShift = determineCycleShift(cycleSubstring);
		result = result * cycleShift / computeGCD(result, cycleShift);
	}

	cout << result << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int testCaseCount;
	cin >> testCaseCount;
	while (testCaseCount--) {
		solveTestCase();
	}

	return 0;
}