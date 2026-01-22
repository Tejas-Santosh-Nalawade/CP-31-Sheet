#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	int testCases;
	cin >> testCases;

	while (testCases--) {
		int rows, columns, k;
		cin >> rows >> columns >> k;

		vector<vector<int>> matrix(rows, vector<int>(columns));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				cin >> matrix[i][j];
			}
		}

		vector<string> binaryStrings(rows);
		for (int i = 0; i < rows; ++i) {
			cin >> binaryStrings[i];
		}

		if (k == 1) {
			cout << "YES" << endl;
			continue;
		}

		vector<vector<int>> prefixSum(rows + 1, vector<int>(columns + 1, 0));
		long long totalDiff = 0;

		for (int i = 0; i < rows; ++i) {
			int current = 0;
			for (int j = 0; j < columns; ++j) {
				if (binaryStrings[i][j] == '1') {
					current += 1;
					totalDiff += matrix[i][j];
				} else {
					totalDiff -= matrix[i][j];
				}
				prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + current;
			}
		}

		if (totalDiff == 0) {
			cout << "YES" << endl;
			continue;
		}

		map<int, int> gcdMap;
		int gcdValue = 0;

		for (int i = 0; i <= rows - k; ++i) {
			for (int j = 0; j <= columns - k; ++j) {
				int subMatrixSum = prefixSum[i + k][j + k] - prefixSum[i + k][j] - prefixSum[i][j + k] + prefixSum[i][j];
				int absDifference = abs(k * k - 2 * subMatrixSum);
				gcdValue = gcd(gcdValue, absDifference);
			}
		}

		if (gcdValue != 0 && totalDiff % gcdValue == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}