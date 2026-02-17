#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e14;


vector<long long> dijkstra(const vector<vector<pair<int, int>>> &graph, int source, int nodeCount) {
	vector<long long> distances(2 * nodeCount + 5, INF);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;

	distances[source] = 0;
	minHeap.push({0, source});

	while (!minHeap.empty()) {
		auto [currentDistance, u] = minHeap.top();
		minHeap.pop();

		if (currentDistance > distances[u]) continue;

		for (const auto &[v, weight] : graph[u]) {
			// If a shorter path is found, update the distance and push to heap
			if (distances[v] > distances[u] + weight) {
				distances[v] = distances[u] + weight;
				minHeap.push({distances[v], v});
			}
		}
	}

	return distances;
}

int main() {
	int testCases;
	cin >> testCases;

	while (testCases--) {
		int numNodes, numEdges, numHorses;
		cin >> numNodes >> numEdges >> numHorses;

		vector<vector<pair<int, int>>> graph(2 * numNodes + 5);
		vector<int> horseStartPositions(numHorses);
		
		for (int &position : horseStartPositions) {
			cin >> position;
		}

		for (int i = 0; i < numEdges; ++i) {
			int a, b, weight;
			cin >> a >> b >> weight;
			graph[2 * a].emplace_back(2 * b, weight);
			graph[2 * b].emplace_back(2 * a, weight);
			graph[2 * a + 1].emplace_back(2 * b + 1, weight / 2);
			graph[2 * b + 1].emplace_back(2 * a + 1, weight / 2);
		}

		for (int i = 1; i <= numNodes; ++i) {
			graph[2 * i + 1].emplace_back(2 * i, 0);
		}

		for (int start : horseStartPositions) {
			graph[2 * start].emplace_back(2 * start + 1, 0);
		}

		vector<long long> distanceFromStart = dijkstra(graph, 2, numNodes);
		vector<long long> distanceFromEnd = dijkstra(graph, 2 * numNodes, numNodes);

		long long minMaxDistance = INF;
		for (int i = 2; i <= 2 * numNodes + 1; ++i) {
			minMaxDistance = min(minMaxDistance, max(distanceFromStart[i], distanceFromEnd[i]));
		}

		cout << (minMaxDistance == INF ? -1 : minMaxDistance) << '\n';
	}

	return 0;
}
