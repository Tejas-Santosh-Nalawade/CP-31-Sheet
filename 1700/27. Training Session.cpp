#include<bits/stdc++.h>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int testCases;
	std::cin >> testCases;

	while (testCases--) {
		int numPairs;
		std::cin >> numPairs;

		std::vector<int> firstElements(numPairs), secondElements(numPairs);
		std::vector<int> firstCount(numPairs + 1), secondCount(numPairs + 1);

		for (int i = 0; i < numPairs; ++i) {
			std::cin >> firstElements[i] >> secondElements[i];
			firstCount[firstElements[i]]++;
			secondCount[secondElements[i]]++;
		}

		long long totalCombinations = static_cast<long long>(numPairs) * (numPairs - 1) * (numPairs - 2) / 6;

		for (int i = 0; i < numPairs; ++i) {
			totalCombinations -= static_cast<long long>(firstCount[firstElements[i]] - 1) * (secondCount[secondElements[i]] - 1);
		}

		std::cout << totalCombinations << '\n';
	}

	return 0;
}