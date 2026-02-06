#include<bits/stdc++.h>

using namespace std;

int main() {
	int numRows, numCols;
	std::cin >> numRows >> numCols;
	std::vector<int> heights(numCols);
	for (int i = 0; i < numCols; ++i) std::cin >> heights[i];

	int logSize = 0;
	while ((1 << logSize) <= numCols) ++logSize;
	std::vector<std::vector<int>> sparseTable(logSize, std::vector<int>(numCols));

	for (int i = 0; i < numCols; ++i) sparseTable[0][i] = heights[i];

	for (int level = 1; level < logSize; ++level) {
		for (int i = 0; i + (1 << level) <= numCols; ++i) {
			sparseTable[level][i] = std::max(sparseTable[level - 1][i],
											 sparseTable[level - 1][i + (1 << (level - 1))]);
		}
	}

	std::vector<int> logValues(numCols + 1, 0);
	for (int i = 2; i <= numCols; ++i) {
		logValues[i] = logValues[i / 2] + 1;
	}

	auto getMaxValue = [&](int left, int right) {
		if (left > right) std::swap(left, right);
		++right;
		int logLen = logValues[right - left];
		return std::max(sparseTable[logLen][left], sparseTable[logLen][right - (1 << logLen)]);
	};

	int numQueries;
	std::cin >> numQueries;
	while (numQueries--) {
		int xs, ys, xf, yf, stepSize;
		std::cin >> xs >> ys >> xf >> yf >> stepSize;
		--xs, --ys, --xf, --yf;


		if (ys % stepSize != yf % stepSize || xs % stepSize != xf % stepSize) {
			std::cout << "NO" << std::endl;
			continue;
		}

		int maxRow = (numRows - xs - 1) / stepSize * stepSize + xs;
		std::cout << (getMaxValue(ys, yf) <= maxRow ? "YES" : "NO") << std::endl;
	}
	return 0;
}