#include<bits/stdc++.h>

void solve() {
	int numElements;
	std::cin >> numElements;
	std::vector<int> elements(numElements);
	for (int& element : elements) {
		std::cin >> element;
	}

	std::vector<int> prefixMax(numElements), suffixMax(numElements);
	for (int i = 0; i < numElements; ++i) {
		prefixMax[i] = elements[i] + i;
		suffixMax[i] = elements[i] - i;
	}

	for (int i = 1; i < numElements; ++i) {
		prefixMax[i] = std::max(prefixMax[i], prefixMax[i - 1]);
	}

	for (int i = numElements - 2; i >= 0; --i) {
		suffixMax[i] = std::max(suffixMax[i], suffixMax[i + 1]);
	}

	int maximumValue = 0;
	for (int mid = 1; mid < numElements - 1; ++mid) {
		maximumValue = std::max(maximumValue, elements[mid] + prefixMax[mid - 1] + suffixMax[mid + 1]);
	}
	std::cout << maximumValue << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int testCases;
	std::cin >> testCases;
	while (testCases--) solve();
	return 0;
}
