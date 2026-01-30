#include<bits/stdc++.h>


const int MAX_VALUE = 1e6;
int frequency[MAX_VALUE + 1];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;
    std::cin >> testCases;

    while (testCases--) {
        int arraySize;
        std::cin >> arraySize;

        std::vector<int> numbers(arraySize);

        for (int i = 0; i < arraySize; ++i) {
            std::cin >> numbers[i];
            ++frequency[numbers[i]];
        }

        long long totalCombinations = 0;

        for (int i = 0; i < arraySize; ++i) {
            int val = numbers[i];

            if (frequency[val] >= 3) {
                totalCombinations += 1LL * (frequency[val] - 1) * (frequency[val] - 2);
            }

            for (long long m = 2; 1LL * val * m * m <= MAX_VALUE; ++m) {
                long long v2 = 1LL * val * m;
                long long v3 = v2 * m;
                totalCombinations += 1LL * frequency[v2] * frequency[v3];
            }
        }

        std::cout << totalCombinations << "\n";

        for (int i = 0; i < arraySize; ++i) {
            --frequency[numbers[i]];
        }
    }

    return 0;
}