#include <bits/stdc++.h>
using namespace std;


int main() {
	int testCases;
	std::cin >> testCases;

	while (testCases--) {
		int arraySize;
		std::cin >> arraySize;
		std::vector<int> numbers(arraySize);

		for (auto &number : numbers) {
			std::cin >> number;
		}

		std::vector<std::vector<int>> prefixCount(200, std::vector<int>(arraySize + 1));
		std::vector<std::vector<int>> positions(200);

		for (int i = 0; i < arraySize; ++i) {
			for (int j = 0; j < 200; ++j) {
				prefixCount[j][i + 1] = prefixCount[j][i];
			}
			++prefixCount[numbers[i] - 1][i + 1];
			positions[numbers[i] - 1].push_back(i);
		}

		int maxSequenceLength = 0;

		for (int i = 0; i < 200; ++i) {
			maxSequenceLength = std::max(maxSequenceLength, static_cast<int>(positions[i].size()));

			for (size_t halfPos = 0; halfPos < positions[i].size() / 2; ++halfPos) {
				int left = positions[i][halfPos] + 1;
				int right = positions[i][positions[i].size() - halfPos - 1] - 1;

				for (int element = 0; element < 200; ++element) {
					int sumInRange = prefixCount[element][right + 1] - prefixCount[element][left];
					maxSequenceLength = std::max(maxSequenceLength, static_cast<int>((halfPos + 1) * 2 + sumInRange));
				}
			}
		}

		std::cout << maxSequenceLength << std::endl;
	}

	return 0;
}
