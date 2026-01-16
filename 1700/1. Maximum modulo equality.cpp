#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

class SegmentTree {
private:
	vector<long long> tree; 
	size_t size; 

	void build(const vector<long long>& arr, size_t index, size_t left, size_t right) {
		if (left == right) {
			tree[index] = arr[left]; 
			return;
		}
		size_t mid = (left + right) / 2;
		build(arr, 2 * index, left, mid); 
		build(arr, 2 * index + 1, mid + 1, right);
		tree[index] = gcd(tree[2 * index], tree[2 * index + 1]); 
	}

	long long query(size_t index, size_t left, size_t right, size_t queryLeft, size_t queryRight) {
		if (queryLeft > right || queryRight < left) {
			return 0; 
		}
		if (queryLeft <= left && right <= queryRight) {
			return tree[index]; 
		}
		size_t mid = (left + right) / 2;
		long long leftGCD = query(2 * index, left, mid, queryLeft, queryRight); 
		long long rightGCD = query(2 * index + 1, mid + 1, right, queryLeft, queryRight); 
		return gcd(leftGCD, rightGCD); 
	}

public:
	SegmentTree(const vector<long long>& arr) : size(arr.size()) {
		if (size > 0) {
			tree.resize(4 * size); 
			build(arr, 1, 0, size - 1); 
		}
	}

	long long rangeGCD(size_t queryLeft, size_t queryRight) {
		if (size == 0) return 0;
		return query(1, 0, size - 1, queryLeft, queryRight);
	}
};

int main() {
	long long testCases;
	cin >> testCases; 
	while (testCases--) {
		size_t arraySize, queries;
		cin >> arraySize >> queries; 
		vector<long long> values(arraySize);
		for (auto& value : values)
			cin >> value; 

		if (arraySize == 1) {
			for (size_t i = 0; i < queries; i++) {
				size_t left, right;
				cin >> left >> right;
				cout << 0 << " ";
			}
			cout << endl;
		} else {
			vector<long long> differences;
			for (size_t i = 1; i < arraySize; i++) {
				differences.push_back(abs(values[i] - values[i - 1]));
			}

			SegmentTree segTree(differences);

			for (size_t i = 0; i < queries; i++) {
				size_t left, right;
				cin >> left >> right;
				if (left == right) {
					cout << 0 << " "; 
				} else {
					cout << segTree.rangeGCD(left - 1, right - 2) << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}