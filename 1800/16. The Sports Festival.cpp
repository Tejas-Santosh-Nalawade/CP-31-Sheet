#include<bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int MAX_SIZE = 2005;

ll memo[MAX_SIZE][MAX_SIZE];

ll elements[MAX_SIZE];

ll minimumDifferenceSum(int left, int right) {
	if (memo[left][right] != -1) {
		return memo[left][right];
	}
	if (left == right) {
		return 0;
	}
	return memo[left][right] = elements[right] - elements[left] + min(minimumDifferenceSum(left + 1, right), minimumDifferenceSum(left, right - 1));
}

int main() {
	int numberOfElements;
	cin >> numberOfElements;

	for (int i = 0; i < numberOfElements; ++i) {
		cin >> elements[i];
	}

	sort(elements, elements + numberOfElements);

	memset(memo, -1, sizeof(memo));

	cout << minimumDifferenceSum(0, numberOfElements - 1) << '\n';
}