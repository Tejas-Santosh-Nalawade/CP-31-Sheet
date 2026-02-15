#include<bits/stdc++.h>

using namespace std;
bool canPartitionWithEqualSum(const std::vector<int>& numbers) {
	int totalSum = std::accumulate(numbers.begin(), numbers.end(), 0);
	if (totalSum % 2 != 0) {
		return false;
	}

	int targetSum = totalSum / 2;
	bitset<200005> subsetSums;
	subsetSums[0] = 1;

	for (int number : numbers) {
		subsetSums |= (subsetSums << number);
	}

	return subsetSums[targetSum];
}

int main() {
	int arraySize;
	cin >> arraySize;
	vector<int> numbers(arraySize);

	for (int& number : numbers) {
		cin >> number;
	}

	if (canPartitionWithEqualSum(numbers)) {
		pair<int, int> minTrailingZeros(INT_MAX, 0);

		for (int i = 0; i < arraySize; ++i) {
			int trailingZeros = __builtin_ctz(numbers[i]);
			if (trailingZeros < minTrailingZeros.first) {
				minTrailingZeros = {trailingZeros, i + 1};
			}
		}

		cout << "1\n" << minTrailingZeros.second;
	} else {
		cout << "0";
	}

	return 0;
}