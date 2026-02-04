#include<bits/stdc++.h>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int testCases;
	std::cin >> testCases; 
	while (testCases--) {
		long long size;
		std::cin >> size; 

		std::vector<int> array(size); 
		std::vector<int> xorFrequency(2 * size, 0); 

		for (int &element : array) {
			std::cin >> element;
		}

		long long matchingPairs = 0;
		int currentXor = 0;
		xorFrequency[currentXor]++;

		for (const int &element : array) {
			currentXor ^= element;

			for (long long i = 0; i * i < 2 * size; i++) {
				if ((currentXor ^ (i * i)) < 2 * size) {
					matchingPairs += xorFrequency[currentXor ^ (i * i)];
				}
			}

			xorFrequency[currentXor]++;
		}

		long long totalPairs = (size * (size + 1)) / 2;
		long long result = totalPairs - matchingPairs;
		std::cout << result << '\n';
	}
}