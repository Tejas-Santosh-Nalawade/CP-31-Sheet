#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 300100;        
const int MAXVAL = 300100;      
const int INF = 1e9;

vector<int> primeAdj[MAXVAL];   
int distanceToPrime[MAXVAL];    
int previousPrime[MAXVAL];      
int previousSpider[MAXVAL];     
int minPrimeFactor[MAXVAL];
int legValueToSpider[MAXVAL]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> legs(n);
    for (int i = 0; i < n; i++) {
        cin >> legs[i];
        legValueToSpider[legs[i]] = i;
    }

    int srcIndex, dstIndex;
    cin >> srcIndex >> dstIndex;
    --srcIndex;
    --dstIndex;

    if (legs[srcIndex] == legs[dstIndex]) {
        if (srcIndex == dstIndex) {
            cout << "1\n" << srcIndex + 1 << '\n';
        } else if (legs[srcIndex] == 1) {
            cout << -1;
        } else {
            cout << "2\n" << srcIndex + 1 << " " << dstIndex + 1;
        }
        return 0;
    }

    fill(minPrimeFactor, minPrimeFactor + MAXVAL, INF);
    for (int p = 2; p < MAXVAL; p++) {
        if (minPrimeFactor[p] != INF) continue;
        minPrimeFactor[p] = p;
        if ((ll)p * p >= MAXVAL) continue;
        for (int x = p * p; x < MAXVAL; x += p) {
            minPrimeFactor[x] = min(minPrimeFactor[x], p);
        }
    }

    fill(distanceToPrime, distanceToPrime + MAXVAL, INF);
    fill(previousPrime, previousPrime + MAXVAL, -1);
    fill(previousSpider, previousSpider + MAXVAL, -1);

    queue<int> q;
    vector<int> primeOwner(MAXVAL, -1); 

    for (int i = 0; i < n; i++) {
        int value = legs[i];
        int prevPrime = -1;
        bool needToFill = primeAdj[value].empty();
        while (value > 1) {
            int p = minPrimeFactor[value];
            if (p != prevPrime && needToFill) {
                primeAdj[legs[i]].push_back(p);
            }
            if (p != prevPrime && i == srcIndex) {
                distanceToPrime[p] = 0;
                q.push(p);
            }
            prevPrime = p;
            primeOwner[p] = i;
            value /= p;
        }
    }

    vector<bool> visitedValue(MAXVAL, false);

    while (!q.empty()) {
        int currPrime = q.front();
        q.pop();

        for (int multiple = currPrime * 2; multiple < MAXVAL; multiple += currPrime) {
            if (visitedValue[multiple]) continue;
            visitedValue[multiple] = true;

            for (int nextPrime : primeAdj[multiple]) {
                if (distanceToPrime[nextPrime] == INF) {
                    distanceToPrime[nextPrime] = distanceToPrime[currPrime] + 1;
                    previousSpider[nextPrime] = legValueToSpider[multiple];
                    previousPrime[nextPrime] = currPrime;
                    q.push(nextPrime);
                }
            }
        }
    }

    int bestPrime = -1;
    int bestDist = INF;
    for (int p : primeAdj[legs[dstIndex]]) {
        if (distanceToPrime[p] < bestDist) {
            bestDist = distanceToPrime[p];
            bestPrime = p;
        }
    }

    if (bestDist == INF) {
        cout << -1;
        return 0;
    }

    vector<int> route;
    route.push_back(dstIndex);
    route.push_back(previousSpider[bestPrime]);
    int p = bestPrime;
    while (previousPrime[p] != -1) {
        p = previousPrime[p];
        route.push_back(previousSpider[p]);
    }
    reverse(route.begin(), route.end());
    route.front() = srcIndex;

    cout << route.size() << '\n';
    for (int idx : route) cout << idx + 1 << ' ';
    cout << '\n';
    return 0;
}