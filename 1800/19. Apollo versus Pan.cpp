#include<bits/stdc++.h>
using namespace std;

using LongLong = long long int;

const int MAX_VALUES = 500000;
const int MAX_BITS = 60;
const int MODULO = 1000000007;

LongLong input[MAX_VALUES];
int bitCount[MAX_BITS];

void solve() {
    int totalNumbers;
    scanf("%d", &totalNumbers);

    fill(bitCount, bitCount + MAX_BITS, 0);

    for (int i = 0; i < totalNumbers; ++i) {
        scanf("%lld", &input[i]);
        for (int j = 0; j < MAX_BITS; ++j) {
            bitCount[j] += (input[i] >> j) & 1;
        }
    }

    LongLong result = 0;

    for (int i = 0; i < totalNumbers; ++i) {
        LongLong expectedOr = 0, expectedAnd = 0;

        for (int j = 0; j < MAX_BITS; ++j) {
            LongLong powerOfTwo = (1LL << j) % MODULO;

            if ((input[i] >> j) & 1) {
                expectedOr = (expectedOr + powerOfTwo * totalNumbers % MODULO) % MODULO;
                expectedAnd = (expectedAnd + powerOfTwo * bitCount[j] % MODULO) % MODULO;
            } else {
                expectedOr = (expectedOr + powerOfTwo * bitCount[j] % MODULO) % MODULO;
            }
        }

        result = (result + expectedOr * expectedAnd % MODULO) % MODULO;
    }

    printf("%lld\n", result);
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        solve();
    }

    return 0;
}