#include <bits/stdc++.h>

const int64_t INF = std::numeric_limits<int64_t>::max();

void solve() {
	int vertexCount, edgeCount;
	std::cin >> vertexCount >> edgeCount;
	std::vector<std::vector<std::pair<int, int>>> adjacencyList(vertexCount);

	for (int i = 0; i < edgeCount; ++i) {
		int start, end, weight;
		std::cin >> start >> end >> weight;
		--start, --end; 
		adjacencyList[start].emplace_back(end, weight);
		adjacencyList[end].emplace_back(start, weight);
	}

	std::vector<int> nodeValues(vertexCount);
	for (int& value : nodeValues) {
		std::cin >> value;
	}

	std::vector<std::vector<int64_t>> distances(vertexCount, std::vector<int64_t>(1001, INF));
	std::vector<std::vector<bool>> visited(vertexCount, std::vector<bool>(1001, false));

	distances[0][nodeValues[0]] = 0;
	std::priority_queue<std::array<int64_t, 3>> priorityQueue;
	priorityQueue.push({0, 0, nodeValues[0]});

	while (!priorityQueue.empty()) {
		int currentNode = priorityQueue.top()[1];
		int currentK = priorityQueue.top()[2];
		priorityQueue.pop();

		if (visited[currentNode][currentK] || distances[currentNode][currentK] == INF) {
			continue;
		}

		visited[currentNode][currentK] = true;

		for (const auto& neighbor : adjacencyList[currentNode]) {
			int neighborNode = neighbor.first;
			int edgeWeight = neighbor.second;
			int newK = std::min(nodeValues[neighborNode], currentK);

			if (distances[neighborNode][newK] > distances[currentNode][currentK] + static_cast<int64_t>(edgeWeight) * currentK) {
				distances[neighborNode][newK] = distances[currentNode][currentK] + static_cast<int64_t>(edgeWeight) * currentK;
				priorityQueue.push({-distances[neighborNode][newK], neighborNode, newK});
			}
		}
	}
	int64_t minimumCost = INF;
	for (int k = 1; k <= 1000; ++k) {
		minimumCost = std::min(minimumCost, distances[vertexCount - 1][k]);
	}
	std::cout << minimumCost << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int testCases;
	std::cin >> testCases;
	while (testCases--) {
		solve();
	}
}