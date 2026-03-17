#include <bits/stdc++.h>
using namespace std;

const int MAX = 2003;

bool isSolutionValid = true;
int parents[MAX], constraints[MAX];
vector<int> adjacencyList[MAX];

vector<pair<int, int>> depthFirstSearch(int currentNode, int parentNode) {
	vector<pair<int, int>> nodeValues;

	for (int childNode : adjacencyList[currentNode]) {
		if (childNode != parentNode) {
			auto childNodeValues = depthFirstSearch(childNode, currentNode);
			nodeValues.insert(nodeValues.end(), childNodeValues.begin(), childNodeValues.end());
		}
	}
	sort(nodeValues.begin(), nodeValues.end());

	if (constraints[currentNode] > nodeValues.size()) {
		isSolutionValid = false;
		nodeValues.emplace_back(currentNode, currentNode);
		return nodeValues;
	}

	if (constraints[currentNode] == 0) {
		if (nodeValues.empty()) {
			nodeValues.emplace_back(currentNode, currentNode);
		} else {
			nodeValues.emplace_back(nodeValues.front().first - 1, currentNode);
		}
	} else {
		int newValue = nodeValues[constraints[currentNode] - 1].first + 1;
		for (int i = constraints[currentNode]; i < nodeValues.size(); i++) {
			nodeValues[i].first += 2;
		}
		nodeValues.emplace_back(newValue, currentNode);
	}
	sort(nodeValues.begin(), nodeValues.end());
	return nodeValues;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int nodeCount;
	cin >> nodeCount;
	int root = -1;
	for (int i = 1; i <= nodeCount; i++) {
		cin >> parents[i] >> constraints[i];
		adjacencyList[parents[i]].push_back(i);
		if (parents[i] == 0) root = i;
	}

	auto result = depthFirstSearch(root, 0);

	if (!isSolutionValid) {
		cout << "NO\n";
		return 0;
	}

	vector<int> nodeOrder(nodeCount + 1);
	int minValue = 0;
	for (auto [value, node] : result) {
		nodeOrder[node] = value;
		minValue = min(minValue, value);
	}
	cout << "YES\n";
	for (int i = 1; i <= nodeCount; i++) {
		cout << nodeOrder[i] - minValue + 1 << " ";
	}

	return 0;
}
