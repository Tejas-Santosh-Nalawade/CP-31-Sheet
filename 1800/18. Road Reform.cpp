#include<bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
public:
    int size; 
    vector<int> parent; 
    vector<int> componentSize; 

    DisjointSetUnion(int size) : size(size), parent(size), componentSize(size, 1) {
        iota(parent.begin(), parent.end(), 0); 
    }

    int find(int node) {
        return (parent[node] == node ? node : parent[node] = find(parent[node]));
    }

    void unite(int node1, int node2) {
        node1 = find(node1);
        node2 = find(node2);
        if (node1 == node2) return; 
        if (componentSize[node1] > componentSize[node2]) swap(node1, node2);
        parent[node1] = node2;
        componentSize[node2] += componentSize[node1];
    }
};

void solve() {
    int numNodes, numEdges, k;
    cin >> numNodes >> numEdges >> k;

    vector<pair<int, pair<int, int>>> edges(numEdges);
    for (int i = 0; i < numEdges; i++) {
        int nodeA, nodeB, cost;
        cin >> nodeA >> nodeB >> cost;
        nodeA--; nodeB--;
        edges[i] = {cost, {nodeA, nodeB}};
    }

    sort(edges.begin(), edges.end());
    auto modifiedEdges = edges;

    vector<pair<long long, pair<int, int>>> zeroCostEdges;
    for (int i = 0; i < numEdges; i++) {
        modifiedEdges[i].first = static_cast<int>(max(0LL, static_cast<long long>(edges[i].first - k)));
        if (edges[i].first <= k) {
            zeroCostEdges.push_back({static_cast<long long>(k - edges[i].first), edges[i].second});
        }
    }

    long long totalCost1 = 0, minimumCostAboveZero1 = LLONG_MAX, minimumCostAboveZero2 = LLONG_MAX;
    DisjointSetUnion dsu1(numNodes);

    sort(modifiedEdges.begin(), modifiedEdges.end());
    for (const auto& [weight, nodes] : modifiedEdges) {
        auto [nodeA, nodeB] = nodes;
        if (weight) minimumCostAboveZero1 = min(minimumCostAboveZero1, static_cast<long long>(weight));
        if (dsu1.find(nodeA) != dsu1.find(nodeB)) {
            dsu1.unite(nodeA, nodeB);
            totalCost1 += weight;
        }
    }

    if (totalCost1 == 0) totalCost1 = minimumCostAboveZero1;

    int requiredEdges = 0;
    DisjointSetUnion dsu2(numNodes);

    sort(zeroCostEdges.begin(), zeroCostEdges.end());
    for (const auto& [weight, nodes] : zeroCostEdges) {
        auto [nodeA, nodeB] = nodes;
        if (dsu2.find(nodeA) != dsu2.find(nodeB)) {
            dsu2.unite(nodeA, nodeB);
            minimumCostAboveZero2 = min(minimumCostAboveZero2, weight);
            requiredEdges++;
        }
    }

    if (requiredEdges != numNodes - 1) minimumCostAboveZero2 = LLONG_MAX;

    cout << min(totalCost1, minimumCostAboveZero2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;
    while (testCases--) solve();

    return 0;
}