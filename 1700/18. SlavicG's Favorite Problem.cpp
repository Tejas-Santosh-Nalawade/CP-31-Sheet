#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int MAX_NODES = 100010;

vector<pair<int, int>> adjacencyList[MAX_NODES];

set<int> xorValues;

int numNodes, nodeA, nodeB;

void depthFirstSearch1(int currentNode, int parent, int currentXor) {
	if (currentNode == nodeB) return;
	xorValues.insert(currentXor);
	for (const auto& edge : adjacencyList[currentNode]) {
		int neighbor = edge.first, weight = edge.second;
		if (neighbor == parent) continue;
		depthFirstSearch1(neighbor, currentNode, currentXor ^ weight);
	}
}

bool depthFirstSearch2(int currentNode, int parent, int currentXor) {
	if (currentNode != nodeB && xorValues.count(currentXor)) return true;
	for (const auto& edge : adjacencyList[currentNode]) {
		int neighbor = edge.first, weight = edge.second;
		if (neighbor == parent) continue;
		if (depthFirstSearch2(neighbor, currentNode, weight ^ currentXor)) return true;
	}
	return false;
}

void solve() {
	xorValues.clear();
	cin >> numNodes >> nodeA >> nodeB;
	--nodeA, --nodeB;
	for (int i = 0; i < numNodes; ++i) adjacencyList[i].clear();
	for (int i = 0; i < numNodes - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		adjacencyList[u].emplace_back(v, w);
		adjacencyList[v].emplace_back(u, w);
	}
	depthFirstSearch1(nodeA, -1, 0);
	if (depthFirstSearch2(nodeB, -1, 0)) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCases;
	cin >> testCases;
	while (testCases--) {
		solve();
	}
	return 0;
}
