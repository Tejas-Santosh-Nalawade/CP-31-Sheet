#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using Edge = pair<ll, ll>;

const ll INF = 1e9 + 7;
const ll MOD = 998244353;

vector<vector<Edge>> adjacencyList;
vector<int> color;
bool isValid;
int crewCounts[2];

void depthFirstSearch(int index, int totalNodes) {
	crewCounts[color[index]] += (index <= totalNodes);
	
	for (const auto& edge : adjacencyList[index]) {
		if (color[edge.first] == -1) {
			color[edge.first] = color[index] ^ edge.second;
			depthFirstSearch(edge.first, totalNodes);
		} 
		else if (color[edge.first] != (color[index] ^ edge.second)) {
			isValid = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int testCases;
	cin >> testCases;
	
	while (testCases--) {
		int originalNodes, maxFakeNodes;
		cin >> originalNodes >> maxFakeNodes;
		
		int totalNodes = originalNodes + maxFakeNodes;
		adjacencyList.assign(totalNodes + 5, vector<Edge>());
		color.assign(totalNodes + 5, -1);
		
		int nextFakeNode = originalNodes + 1;
		
		for (int i = 0; i < maxFakeNodes; ++i) {
			int nodeA, nodeB;
			string relationship;
			cin >> nodeA >> nodeB >> relationship;
			
			if (relationship == "crewmate") {
				adjacencyList[nodeA].emplace_back(nextFakeNode, 1);
				adjacencyList[nextFakeNode].emplace_back(nodeA, 1);
				adjacencyList[nextFakeNode].emplace_back(nodeB, 1);
				adjacencyList[nodeB].emplace_back(nextFakeNode, 1);
				++nextFakeNode;
			} else {
				adjacencyList[nodeA].emplace_back(nodeB, 1);
				adjacencyList[nodeB].emplace_back(nodeA, 1);
			}
		}
		
		int maxCrews = 0;
		isValid = true;
		
		for (int i = 1; i <= originalNodes; ++i) {
			if (color[i] == -1) {
				color[i] = 0;
				crewCounts[0] = crewCounts[1] = 0;
				depthFirstSearch(i, originalNodes);
				maxCrews += max(crewCounts[0], crewCounts[1]);
			}
		}
		
		if (!isValid) {
			maxCrews = -1;
		}
		
		cout << maxCrews << "\n";
	}
	
	return 0;
}