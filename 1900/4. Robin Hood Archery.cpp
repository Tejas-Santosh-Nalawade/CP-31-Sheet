#include <bits/stdc++.h>
using namespace std;

long long getRandomUpto1e16() {
	static std::mt19937_64 rng(std::random_device{}());
	static std::uniform_int_distribution<long long> dist(0, 10000000000000000LL);
	return dist(rng);
}

int main() {
	long long testCases;
	cin >> testCases;
	map<long long, long long> precomputedHashes;
	for (long long i = 1; i <= 1e6; ++i) {
		precomputedHashes[i] = getRandomUpto1e16();
	}

	while (testCases--) {
		long long arraySize, queries;
		cin >> arraySize >> queries; 

		vector<long long> elements(arraySize);
		for (long long &element : elements) {
			cin >> element;
		}

		vector<long long> hashValues(arraySize);
		for (long long i = 0; i < arraySize; ++i) {
			hashValues[i] = precomputedHashes[elements[i]];
		}

		vector<long long> prefixXor(arraySize + 1, 0);
		prefixXor[1] = hashValues[0];
		for (long long i = 2; i <= arraySize; ++i) {
			prefixXor[i] = prefixXor[i - 1] ^ hashValues[i - 1];
		}

		for (long long i = 0; i < queries; ++i) {
			long long left, right;
			cin >> left >> right; 
			--left; 

			long long xorResult = prefixXor[right] ^ prefixXor[left];
			cout << (xorResult == 0 ? "YES" : "NO") << endl;
		}
	}
}