#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int arraySize, queryCount;
    cin >> arraySize >> queryCount;

    vector<int> values(arraySize + 2, 0);
    for (int index = 1; index <= arraySize; ++index) {
        cin >> values[index];
    }

    long long totalWeight = 0;
    for (int index = 1; index <= arraySize; ++index) {
        if (values[index] != values[index + 1]) {
            totalWeight += 1LL * (arraySize - index) * index;
        }
    }

    while (queryCount--) {
        int position, newValue;
        cin >> position >> newValue;

        if (values[position] != values[position - 1]) {
            totalWeight -= 1LL * (arraySize - position + 1) * (position - 1);
        }
        if (values[position + 1] != values[position]) {
            totalWeight -= 1LL * (arraySize - position) * position;
        }

        values[position] = newValue;

        if (values[position] != values[position - 1]) {
            totalWeight += 1LL * (arraySize - position + 1) * (position - 1);
        }
        if (values[position + 1] != values[position]) {
            totalWeight += 1LL * (arraySize - position) * position;
        }

        cout << totalWeight + 1LL * arraySize * (arraySize + 1) / 2 << '\n';
    }

    return 0;
}