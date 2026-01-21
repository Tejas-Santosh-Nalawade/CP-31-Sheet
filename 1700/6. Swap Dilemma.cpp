#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 2e5 + 5;

class BinaryIndexedTree {
public:
	BinaryIndexedTree(int size) : tree(size + 1, 0) {}

	void update(int index, int value) {
		while (index < tree.size()) {
			tree[index] += value;
			index += index & -index;
		}
	}

	int query(int index) {
		int sum = 0;
		while (index > 0) {
			sum += tree[index];
			index -= index & -index;
		}
		return sum;
	}

	void clear() {
		fill(tree.begin(), tree.end(), 0);
	}

private:
	vector<int> tree; 
};

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return (a / gcd(a, b)) * b;
}

long long power(long long base, long long exp) {
	long long result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) result *= base;
		base *= base;
		exp /= 2;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int test_cases;
	cin >> test_cases;
	vector<string> results;
	BinaryIndexedTree bit1(MAX_VAL), bit2(MAX_VAL);

	while (test_cases--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		map<int, int> freq1, freq2;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			freq1[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			freq2[b[i]]++;
		}

		if (freq1 != freq2) {
			results.push_back("NO");
			continue;
		}

		bool has_duplicate = any_of(freq1.begin(), freq1.end(), [](const auto& p) { return p.second >= 2; });

		bit1.clear();
		bit2.clear();
		long long inversions_a = 0, inversions_b = 0;

		for (int i = n - 1; i >= 0; i--) {
			inversions_a += bit1.query(a[i] - 1);
			inversions_b += bit2.query(b[i] - 1);
			bit1.update(a[i], 1);
			bit2.update(b[i], 1);
		}

		if (has_duplicate || (inversions_a % 2 == inversions_b % 2)) {
			results.push_back("YES");
		} else {
			results.push_back("NO");
		}
	}

	for (const string& result : results) {
		cout << result << '\n';
	}

	return 0;
}