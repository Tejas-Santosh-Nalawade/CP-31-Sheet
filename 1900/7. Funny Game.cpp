#include <bits/stdc++.h>
using namespace std;


int findGCD(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int findLCM(int a, int b) {
	return (a / findGCD(a, b)) * b;
}

int calculatePower(int base, int exponent) {
	int result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			result *= base;
		}
		base *= base;
		exponent /= 2;
	}
	return result;
}

int main() {
	int testCases;
	std::cin >> testCases;

	while (testCases--) {
		int arraySize;
		std::cin >> arraySize;

		std::vector<int> array(arraySize);
		for (int& element : array) std::cin >> element;

		std::vector<int> positions(arraySize);
		std::iota(positions.begin(), positions.end(), 0);

		std::vector<std::pair<int, int>> pairs;

		for (int i = arraySize - 1; i >= 1; --i) {
			std::vector<int> remainder(i, -1);

			for (int index : positions) {
				int currentRemainder = array[index] % i;

				if (remainder[currentRemainder] != -1) {
					pairs.emplace_back(index, remainder[currentRemainder]);
					positions.erase(std::find(positions.begin(), positions.end(), index));
					break;
				}

				remainder[currentRemainder] = index;
			}
		}

		std::reverse(pairs.begin(), pairs.end());
		std::cout << "YES" << std::endl;

		for (const auto& pair : pairs) {
			std::cout << pair.first + 1 << " " << pair.second + 1 << std::endl;
		}
	}

	return 0;
}