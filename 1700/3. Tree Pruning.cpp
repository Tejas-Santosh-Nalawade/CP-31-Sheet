#include <bits/stdc++.h>

using namespace std;

using namespace std;

long long maxLevel;

void depthFirstSearch(long long node, long long parent, long long level, vector<long long>& nodesAtLevel, vector<long long>& maxDepthOfNode, vector<long long> adj[]) {
	maxLevel = max(maxLevel, level);

	nodesAtLevel[level]++;
	maxDepthOfNode[node] = level;

	for (auto child : adj[node]) {
		if (child != parent) {
			depthFirstSearch(child, node, level + 1, nodesAtLevel, maxDepthOfNode, adj);
			maxDepthOfNode[node] = max(maxDepthOfNode[node], maxDepthOfNode[child]);
		}
	}
}

void solve() {
	long long numNodes;
	cin >> numNodes;
	vector<long long> adj[numNodes + 1];
	maxLevel = 0;

	for (long long i = 0; i < numNodes - 1; i++) {
		long long x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<long long> maxDepthOfNode(numNodes + 1, 0);
    
	vector<long long> nodesAtLevel(numNodes + 1, 0);

	depthFirstSearch(1, -1, 1, nodesAtLevel, maxDepthOfNode, adj);

	vector<long long> prefixSumOfDepth(numNodes + 3, 0);

	for (long long i = 1; i <= numNodes; i++) {
		prefixSumOfDepth[maxDepthOfNode[i]]++;
	}

	for (long long i = 1; i <= numNodes; i++) {
		prefixSumOfDepth[i] += prefixSumOfDepth[i - 1];
		nodesAtLevel[i] += nodesAtLevel[i - 1];
	}

	long long result = numNodes - 1;

	for (long long i = 1; i <= maxLevel; i++) {
		long long extraNodesToDelete = nodesAtLevel[maxLevel] - nodesAtLevel[i];
		extraNodesToDelete += prefixSumOfDepth[i - 1];
		result = min(result, extraNodesToDelete);
	}

	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long testCases;
	cin >> testCases;
	while (testCases--)
		solve();

	return 0;
}
