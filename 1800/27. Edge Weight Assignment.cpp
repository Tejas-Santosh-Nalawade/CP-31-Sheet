#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<bool, bool> dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& leafCounts, bool& hasMixedParity) {
    if (adj[node].size() == 1) return {1, 0}; 

    int leafChildCount = 0;
    bool hasEvenLeaf = false, hasOddLeaf = false;

    for (auto& child : adj[node]) {
        if (child == parent) continue;
        auto childParity = dfs(child, node, adj, leafCounts, hasMixedParity);
        hasEvenLeaf |= childParity.first;
        hasOddLeaf  |= childParity.second;
        if (adj[child].size() == 1) leafChildCount++; 
    }

    if (hasEvenLeaf & hasOddLeaf) hasMixedParity = true;
    if (leafChildCount) leafCounts.push_back(leafChildCount);

    return {hasOddLeaf, hasEvenLeaf};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    int root = -1;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        if (adj[u].size() >= 2) root = u;
        if (adj[v].size() >= 2) root = v;
    }

    bool hasMixedParity = false;
    vector<int> leafCounts;

    dfs(root, -1, adj, leafCounts, hasMixedParity);

    int sumLeafCounts = accumulate(leafCounts.begin(), leafCounts.end(), 0LL);
    
    cout << (hasMixedParity ? 3 : 1) << " " << n - 1 - sumLeafCounts + leafCounts.size() << endl;

    return 0;
}