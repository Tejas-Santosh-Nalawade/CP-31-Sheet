#include <bits/stdc++.h>
using namespace std;

struct SegmentTreeNode {
	int minVal; 
	int maxVal; 
};


class SegmentTree {
	vector<SegmentTreeNode> tree; 
	vector<int>& elements; 
	map<int, bool>& visited; 
	int size; 

public:
	SegmentTree(vector<int>& arr, map<int, bool>& visitedMap) : elements(arr), visited(visitedMap) {
		size = elements.size();
		tree.resize(4 * size); 
		build(1, 0, size - 1); 
	}

	void build(int node, int start, int end) {
		if (start == end) {
			if (!visited[elements[start]]) {
				tree[node] = {elements[start], elements[start]};
			} else {
				tree[node] = {INT_MAX, INT_MIN};
			}
			return;
		}
		int mid = (start + end) / 2;
		build(2 * node, start, mid); 
		build(2 * node + 1, mid + 1, end); 
		tree[node].minVal = min(tree[2 * node].minVal, tree[2 * node + 1].minVal);
		tree[node].maxVal = max(tree[2 * node].maxVal, tree[2 * node + 1].maxVal); 
	}

	SegmentTreeNode query(int node, int start, int end, int left, int right) {
		if (right < start || left > end) return {INT_MAX, INT_MIN}; 
		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) / 2;
		SegmentTreeNode leftQuery = query(2 * node, start, mid, left, right); 
		SegmentTreeNode rightQuery = query(2 * node + 1, mid + 1, end, left, right); 
		return {
			min(leftQuery.minVal, rightQuery.minVal),
			max(leftQuery.maxVal, rightQuery.maxVal)
		};
	}

	SegmentTreeNode rangeQuery(int left, int right) {
		return query(1, 0, size - 1, left, right);
	}

	void update(int node, int start, int end, int pos) {
		if (start == end) {
			if (!visited[elements[pos]]) {
				tree[node] = {elements[pos], elements[pos]};
			} else {
				tree[node] = {INT_MAX, INT_MIN};
			}
			return;
		}

		int mid = (start + end) / 2;
		if (pos <= mid)
			update(2 * node, start, mid, pos);
		else
			update(2 * node + 1, mid + 1, end, pos); 

		tree[node].minVal = min(tree[2 * node].minVal, tree[2 * node + 1].minVal); 
		tree[node].maxVal = max(tree[2 * node].maxVal, tree[2 * node + 1].maxVal); 
	}

	void updatePosition(int pos) {
		update(1, 0, size - 1, pos);
	}
};

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) {
		int numElements;
		cin >> numElements; 
		vector<int> elements(numElements);
		for (int i = 0; i < numElements; i++) cin >> elements[i]; 

		map<int, int> indexMap;
		for (int i = 0; i < numElements; i++) indexMap[elements[i]] = i; 

		set<int> indices;
		for (auto& element : indexMap) indices.insert(element.second); 

		map<int, int> visited;
		int lastUsedIndex = -1;
		int previous = 0;
		vector<int> result; 

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
		priority_queue<pair<int, int>> maxHeap;

		while (!indices.empty()) {
			int currentIndex = *indices.begin();
			for (int i = previous; i <= currentIndex; i++) {
				if (visited[elements[i]] == 0 && i > lastUsedIndex) {
					minHeap.push({elements[i], i}); 
					maxHeap.push({elements[i], numElements - i}); 
				}
			}

			if (result.size() % 2 == 0) {
				while (!maxHeap.empty() && (visited[maxHeap.top().first] || numElements - maxHeap.top().second <= lastUsedIndex)) 
					maxHeap.pop();
				int maxElement = maxHeap.top().first;
				lastUsedIndex = numElements - maxHeap.top().second;
				result.push_back(maxElement);
				visited[maxElement] = 1;
				indices.erase(indexMap[maxElement]);
				maxHeap.pop();
			} else {
				while (!minHeap.empty() && (visited[minHeap.top().first] || minHeap.top().second <= lastUsedIndex)) 
					minHeap.pop();
				int minElement = minHeap.top().first;
				lastUsedIndex = minHeap.top().second;
				result.push_back(minElement);
				visited[minElement] = 1;
				indices.erase(indexMap[minElement]);
				minHeap.pop();
			}

			previous = currentIndex + 1;
		}

		cout << result.size() << endl;
		for (const int& element : result) cout << element << " "; 
		cout << endl;
	}
}
