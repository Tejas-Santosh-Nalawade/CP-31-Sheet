#include <bits/stdc++.h>

using namespace std;

void solve() {
    int itemCount;
    long long multiplier;
    std::cin >> itemCount >> multiplier;

    std::vector<long long> costs(itemCount), happiness(itemCount);
    for (int i = 0; i < itemCount; ++i) {
        std::cin >> costs[i] >> happiness[i];
    }

    long long totalHappiness = std::accumulate(happiness.begin(), happiness.end(), 0LL);

    const long long INF = std::numeric_limits<long long>::max();

    std::vector<long long> minCost(static_cast<size_t>(totalHappiness + 1), INF);
    minCost[0] = 0;

    for (int i = 0; i < itemCount; ++i) {
        for (long long currentHappiness = totalHappiness; currentHappiness >= happiness[i]; --currentHappiness) {
            if (minCost[currentHappiness - happiness[i]] != INF) {
                long long newCost = minCost[currentHappiness - happiness[i]];
                if (newCost <= INF - costs[i]) {
                    long long candidate = newCost + costs[i];
                    if (candidate <= 1LL * i * multiplier) {
                        minCost[currentHappiness] = std::min(minCost[currentHappiness], candidate);
                    }
                }
            }
        }
    }

    for (long long happinessValue = totalHappiness; happinessValue >= 0; --happinessValue) {
        if (minCost[happinessValue] != INF) {
            std::cout << happinessValue << '\n';
            break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}

