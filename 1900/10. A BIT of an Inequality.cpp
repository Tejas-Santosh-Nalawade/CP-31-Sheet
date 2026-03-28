#include <bits/stdc++.h>
using namespace std;
using namespace std;

const int NUM_BITS = 30;
const int MAX_SIZE = 100003;

int prefixCount[NUM_BITS][MAX_SIZE][2];
int suffixCount[NUM_BITS][MAX_SIZE][2];

void solve() {
	int arraySize;
	cin >> arraySize;
	vector<int> array(arraySize + 1);

	for (int i = 1; i <= arraySize; ++i) {
		cin >> array[i];
	}

	for (int bit = 0; bit < NUM_BITS; ++bit) {
		suffixCount[bit][arraySize + 1][0] = suffixCount[bit][arraySize + 1][1] = 0;
	}

	for (int bit = 0; bit < NUM_BITS; ++bit) {
		for (int index = 1; index <= arraySize; ++index) {
			int bitStatus = (array[index] & (1 << bit)) ? 1 : 0;
			for (int k = 0; k < 2; ++k) {
				prefixCount[bit][index][k] = (bitStatus == k) + prefixCount[bit][index - 1][k ^ bitStatus];
			}
		}
		for (int index = arraySize; index >= 1; --index) {
			int bitStatus = (array[index] & (1 << bit)) ? 1 : 0;
			for (int k = 0; k < 2; ++k) {
				suffixCount[bit][index][k] = (bitStatus == k) + suffixCount[bit][index + 1][k ^ bitStatus];
			}
		}
	}

	long long result = 0;
	for (int i = 1; i <= arraySize; ++i) {
		int highestBit = 31 - __builtin_clz(array[i]);
		result += static_cast<long long>(prefixCount[highestBit][i - 1][1]) * (1 + suffixCount[highestBit][i + 1][0]);
		result += static_cast<long long>(1 + prefixCount[highestBit][i - 1][0]) * suffixCount[highestBit][i + 1][1];
	}
	cout << result << "\n";
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) {
		solve();
	}
	return 0;
}