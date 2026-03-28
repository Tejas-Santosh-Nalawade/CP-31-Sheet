#include <bits/stdc++.h>
using namespace std;

#define int long long

using vi = vector<int>;
using vvi = vector<vector<int>>;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int n, m;
    cin >> n >> m;

    vvi adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi subtreeSize(n + 1, 1);
    vi visited(n + 1, 0);

    function<void(int)> dfsSubtree = [&](int node) {
        visited[node] = 1;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsSubtree(neighbor);
                subtreeSize[node] += subtreeSize[neighbor];
            }
        }
    };
    dfsSubtree(1);

    int maxBridgeContribution = 0;
    int timer = 1;
    vi discoveryTime(n + 1, 0);
    vi lowTime(n + 1, 2e9);

    function<void(int, int)> tarjanDFS = [&](int node, int parent) {
        discoveryTime[node] = timer;
        lowTime[node] = timer;
        timer++;

        for (auto neighbor : adj[node]) {
            if (discoveryTime[neighbor] == 0) {
                tarjanDFS(neighbor, node);
                lowTime[node] = min(lowTime[node], lowTime[neighbor]);

                if (lowTime[neighbor] > discoveryTime[node]) {
                    maxBridgeContribution = max(maxBridgeContribution,
                                                subtreeSize[neighbor] * (n - subtreeSize[neighbor]));
                }
            } else if (neighbor != parent) { 
                lowTime[node] = min(lowTime[node], discoveryTime[neighbor]);
            }
        }
    };
    tarjanDFS(1, 0);

    cout << (n * (n - 1)) / 2 - maxBridgeContribution << '\n';
}

signed main() {
    FAST_IO
    int testCases;
    cin >> testCases;
    while (testCases--) solve();
    return 0;
}
