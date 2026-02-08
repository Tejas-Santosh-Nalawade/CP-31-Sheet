#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct SegmentTree {
	struct Node {
		ll prefixMax, suffixMax, maxSubarraySum, totalSum;
	};

	int size;
	vector<Node> tree;

	SegmentTree(int n, ll initialValue) : size(n) {
		tree.resize(4 * n, {initialValue, initialValue, initialValue, initialValue});
		build(1, 0, n - 1, initialValue);
	}

	void build(int index, int left, int right, ll value) {
		if (left == right) {
			tree[index] = {value, value, value, value};
			return;
		}
		int mid = (left + right) / 2;
		build(2 * index, left, mid, value);
		build(2 * index + 1, mid + 1, right, value);
		tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
	}

	Node merge(const Node& a, const Node& b) {
		Node result;
		result.prefixMax = max(a.prefixMax, a.totalSum + b.prefixMax);
		result.suffixMax = max(b.suffixMax, b.totalSum + a.suffixMax);
		result.maxSubarraySum = max({a.maxSubarraySum, b.maxSubarraySum, a.suffixMax + b.prefixMax});
		result.totalSum = a.totalSum + b.totalSum;
		return result;
	}

	void update(int pos, ll value) {
		update(1, 0, size - 1, pos, value);
	}

	void update(int index, int left, int right, int pos, ll value) {
		if (left > pos || right < pos) return;
		if (left == pos && right == pos) {
			tree[index] = {value, value, value, value};
			return;
		}
		int mid = (left + right) / 2;
		update(2 * index, left, mid, pos, value);
		update(2 * index + 1, mid + 1, right, pos, value);
		tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
	}

	Node query(int left, int right) {
		return query(1, 0, size - 1, left, right);
	}

	Node query(int index, int left, int right, int queryLeft, int queryRight) {
		if (left > queryRight || right < queryLeft) return {0, 0, 0, 0};
		if (left >= queryLeft && right <= queryRight) return tree[index];
		int mid = (left + right) / 2;
		Node leftResult = query(2 * index, left, mid, queryLeft, queryRight);
		Node rightResult = query(2 * index + 1, mid + 1, right, queryLeft, queryRight);
		return merge(leftResult, rightResult);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> array(n);
	for (int& item : array) cin >> item;

	map<int, vector<int>> indexMap;
	for (int i = 0; i < n; i++) {
		indexMap[array[i]].push_back(i);
	}

	SegmentTree segmentTree(n, -1);

	ll maxSum = 0, bestValue = -1;
	for (const auto& [value, indices] : indexMap) {
		for (int index : indices) segmentTree.update(index, 1);
		ll currentMaxSum = segmentTree.query(0, n - 1).maxSubarraySum;
		if (maxSum < currentMaxSum) {
			bestValue = value;
			maxSum = currentMaxSum;
		}
		for (int index : indices) segmentTree.update(index, -1);
	}

	int bestLeft = -1, bestRight = -1;
	for (int& item : array) {
		if (item == bestValue) item = 1;
		else item = -1;
	}

	ll currentSum = 0, bestCurrentSum = 0;
	ll start = 0;
	for (int i = 0; i < n; ++i) {
		currentSum += array[i];
		if (currentSum > bestCurrentSum) {
			bestCurrentSum = currentSum;
			bestRight = i;
			bestLeft = start;
		}
		if (currentSum <= 0) {
			start = i + 1;
			currentSum = 0;
		}
	}
	cout << bestValue << " " << bestLeft + 1 << " " << bestRight + 1 << "\n";
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
