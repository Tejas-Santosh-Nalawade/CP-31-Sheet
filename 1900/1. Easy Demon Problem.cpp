#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<int,int>> getFactorPairs(int number) {
    vector<pair<int,int>> factorPairs;
    factorPairs.push_back({1, number});
    for (int divisor = 2; divisor * divisor <= number; divisor++) {
        if (number % divisor == 0) {
            factorPairs.push_back({divisor, number / divisor});
        }
    }
    return factorPairs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sizeA, sizeB, queryCount;
    cin >> sizeA >> sizeB >> queryCount;

    vector<int> arrA(sizeA), arrB(sizeB);
    unordered_map<ll,int> freqA, freqB;
    ll sumA = 0, sumB = 0;

    for (int i = 0; i < sizeA; i++) {
        cin >> arrA[i];
        freqA[arrA[i]]++;
        sumA += arrA[i];
    }

    for (int i = 0; i < sizeB; i++) {
        cin >> arrB[i];
        freqB[arrB[i]]++;
        sumB += arrB[i];
    }

    for (int q = 0; q < queryCount; q++) {
        int queryValue;
        cin >> queryValue;
        int absQuery = abs(queryValue);

        vector<pair<int,int>> factorPairs = getFactorPairs(absQuery);
        bool found = false;

        for (auto [f1, f2] : factorPairs) {
            vector<pair<ll,ll>> candidates;
            if (queryValue >= 0) {
                candidates = {
                    {f1, f2}, {f2, f1}, {-f1, -f2}, {-f2, -f1}
                };
            } else {
                candidates = {
                    {-f1, f2}, {f2, -f1}, {f1, -f2}, {-f2, f1}
                };
            }

            for (auto [x, y] : candidates) {
                if (freqA[sumA - x] > 0 && freqB[sumB - y] > 0) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        cout << (found ? "YES" : "NO") << "\n";
    }

    return 0;
}