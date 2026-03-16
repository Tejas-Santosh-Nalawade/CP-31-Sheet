#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
	struct Node {
		vector<long long> charCount; 
		long long distinctCount;   

		Node() {
			charCount.assign(26, 0);
			distinctCount = 0;
		}

		Node(long long charIndex) {
			charCount.assign(26, 0);
			charCount[charIndex] = 1;
			distinctCount = 1;
		}

		void merge(const Node &left, const Node &right) {
			distinctCount = 0;
			for (int i = 0; i < 26; ++i) {
				charCount[i] = left.charCount[i] + right.charCount[i];
				if (charCount[i] > 0)
					++distinctCount;
			}
		}
	};

	vector<Node> tree; 
	vector<long long> data;
	long long size;
	
	SegmentTree(const vector<long long> &input) {
		size = input.size();
		data = input;
		tree.resize(4 * size, Node());
		build(0, size - 1, 1);
	}

	void build(long long start, long long end, long long index) {
		if (start == end) {
			tree[index] = Node(data[start]);
			return;
		}
		long long mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}

	Node query(long long start, long long end, long long left, long long right, long long index) {
		if (start > right || end < left) {
			return Node();
		}
		if (start >= left && end <= right) {
			return tree[index]; 
		}
		long long mid = (start + end) / 2;
		Node leftResult = query(start, mid, left, right, 2 * index);
		Node rightResult = query(mid + 1, end, left, right, 2 * index + 1);
		Node result;
		result.merge(leftResult, rightResult);
		return result;
	}
	// Public query function
	Node query(long long left, long long right) {
		return query(0, size - 1, left, right, 1);
	}
};

void solve() {
	string inputString;
	cin >> inputString;
	long long queryCount;
	cin >> queryCount;

	long long n = inputString.size();
	vector<long long> charIndices(n);
	for (long long i = 0; i < n; ++i) {
		charIndices[i] = inputString[i] - 'a'; 
	}

	SegmentTree segmentTree(charIndices); 

	for (long long i = 0; i < queryCount; ++i) {
		long long left, right;
		cin >> left >> right;
		--left;
		--right;

		if (left == right) {
			cout << "YES\n";
			continue;
		}

		long long distinctChars = segmentTree.query(left, right).distinctCount;

		if (distinctChars == 1) {
			cout << "NO\n";
		} else if (distinctChars > 2) {
			cout << "YES\n";
		} else {
			if (inputString[left] == inputString[right]) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCases = 1;
	while (testCases--) solve();
	return 0;
}