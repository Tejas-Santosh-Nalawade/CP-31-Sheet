#include <iostream>
using namespace std;

typedef long long ll;

const int MAX_SIZE = 1000077;

int startRange1, endRange1, startRange2, endRange2;

ll arraySum[MAX_SIZE];

int main() {
    cin >> startRange1 >> endRange1 >> startRange2 >> endRange2;

    for (int i = startRange1; i <= endRange1; i++) {
        arraySum[i + endRange1]++;
        arraySum[i + startRange2 + 1]--;
    }

    for (int i = 1; i < MAX_SIZE; i++)
        arraySum[i] += arraySum[i - 1];
    for (int i = 1; i < MAX_SIZE; i++)
        arraySum[i] += arraySum[i - 1];

    ll result = 0;
    for (int i = startRange2; i <= endRange2; i++)
        result += arraySum[MAX_SIZE - 1] - arraySum[i];

    cout << result << endl;

    return 0;
}