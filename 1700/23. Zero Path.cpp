#include<bits/stdc++.h>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int numTests;
  	std::cin >> numTests;

	while (numTests--) {
		int rows, cols;
		std::cin >> rows >> cols;

		std::vector<std::vector<int>> grid(rows, std::vector<int>(cols));
		std::vector<std::vector<int>> minPathSum(rows, std::vector<int>(cols));
		std::vector<std::vector<int>> maxPathSum(rows, std::vector<int>(cols));

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				std::cin >> grid[i][j];

		minPathSum[0][0] = maxPathSum[0][0] = grid[0][0];

		for (int i = 1; i < rows; ++i)
			maxPathSum[i][0] = minPathSum[i][0] = maxPathSum[i - 1][0] + grid[i][0];

		for (int j = 1; j < cols; ++j)
			maxPathSum[0][j] = minPathSum[0][j] = maxPathSum[0][j - 1] + grid[0][j];

		for (int i = 1; i < rows; ++i)
			for (int j = 1; j < cols; ++j) {
				maxPathSum[i][j] = std::max(maxPathSum[i - 1][j], maxPathSum[i][j - 1]) + grid[i][j];
				minPathSum[i][j] = std::min(minPathSum[i - 1][j], minPathSum[i][j - 1]) + grid[i][j];
			}

		if (maxPathSum[rows - 1][cols - 1] % 2 != 0 || minPathSum[rows - 1][cols - 1] > 0 || maxPathSum[rows - 1][cols - 1] < 0) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
		}
	}

	return 0;
}