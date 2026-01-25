#include <bits/stdc++.h>
using namespace std;

void mergeSortedInDescendingOrder() {
	int firstArraySize, secondArraySize;
	std::cin >> firstArraySize >> secondArraySize;

	std::vector<int> firstArray(firstArraySize);
	std::vector<int> secondArray(secondArraySize);

	for (int &element : firstArray) {
		std::cin >> element;
	}

	for (int &element : secondArray) {
		std::cin >> element;
	}

	std::sort(secondArray.rbegin(), secondArray.rend());

	std::vector<int> mergedArray(firstArraySize + secondArraySize);
	std::merge(firstArray.begin(), firstArray.end(), secondArray.begin(), secondArray.end(), mergedArray.begin(), std::greater<int>());

	for (const int &element : mergedArray) {
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int testCases;
	std::cin >> testCases;

	while (testCases--) {
		mergeSortedInDescendingOrder();
	}

	return 0;
}