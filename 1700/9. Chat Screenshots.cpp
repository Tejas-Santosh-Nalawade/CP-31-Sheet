#include <bits/stdc++.h>
using namespace std;

int globalTimer = 0;

void depthFirstSearch(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& finishTime) {
	visited[node] = true; 
	for (int neighbor : graph[node]) {
		if (!visited[neighbor]) {
			depthFirstSearch(neighbor, graph, visited, finishTime);
		}
	}
	finishTime[node] = globalTimer++;
}

void solve() {
	globalTimer = 0;
	int numNodes, numAuthors;
	cin >> numNodes >> numAuthors; 
	vector<vector<int>> authorGraph(numAuthors, vector<int>(numNodes));
	vector<int> authors(numAuthors);
	for (int i = 0; i < numAuthors; ++i) {
		for (int j = 0; j < numNodes; ++j) {
			cin >> authorGraph[i][j];
			authorGraph[i][j]--; 
		}
		authors[i] = authorGraph[i][0]; 
	}
	vector<vector<int>> graph(numNodes);
	for (int i = 0; i < numAuthors; ++i) {
		for (int j = 1; j + 1 < numNodes; ++j) {
			int currentNode = authorGraph[i][j], nextNode = authorGraph[i][j + 1];
			graph[currentNode].push_back(nextNode); 
		}
	}
	vector<int> finishTime(numNodes, -1);
	vector<bool> visited(numNodes, false);
	for (int i = 0; i < numNodes; ++i) {
		if (finishTime[i] == -1) {
			depthFirstSearch(i, graph, visited, finishTime);
		}
	}
	for (int i = 0; i < numAuthors; ++i) {
		for (int j = 1; j + 1 < numNodes; ++j) {
			int currentNode = authorGraph[i][j], nextNode = authorGraph[i][j + 1];
			if (finishTime[currentNode] < finishTime[nextNode]) {
				cout << "NO";
				return;
			}
		}
	}
	cout << "YES";
}

int main() {
	int testCases;
	cin >> testCases; 
	while (testCases--) {
		solve(); 
		cout << "\n";
	}
}
