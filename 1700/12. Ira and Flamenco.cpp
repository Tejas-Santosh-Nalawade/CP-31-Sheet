#include<bits/stdc++.h>
using namespace std;
using IntPair = pair<int, int>;

const int MOD = 1000000007; 

int addMod(int a, int b) {
	return (a + b >= MOD ? a + b - MOD : a + b);
}

int mulMod(int a, int b) {
	return 1LL * a * b % MOD;
}

int solve(int n, int m, vector<int>& arr) {
	vector<int> uniqueElements = arr;
	sort(uniqueElements.begin(), uniqueElements.end());
	uniqueElements.erase(unique(uniqueElements.begin(), uniqueElements.end()), uniqueElements.end());

	vector<int> elementCount(uniqueElements.size());
	for (auto& num : arr) {
		int idx = lower_bound(uniqueElements.begin(), uniqueElements.end(), num) - uniqueElements.begin();
		elementCount[idx]++;
	}

	if (uniqueElements.size() < m) return 0;

	stack<IntPair> stack1, stack2;
	auto push = [](stack<IntPair>& stack, int x) {
		stack.emplace(x, mulMod(x, stack.empty() ? 1 : stack.top().second));
	};

	for (int j = 0; j < m; ++j) {
		push(stack1, elementCount[j]);
	}

	int result = 0; 
	for (size_t j = m; j <= uniqueElements.size(); ++j) {
		if (uniqueElements[j - 1] - uniqueElements[j - m] == m - 1) {
			result = addMod(result, mulMod(stack1.empty() ? 1 : stack1.top().second, stack2.empty() ? 1 : stack2.top().second));
		}

		if (stack2.empty()) {
			while (!stack1.empty()) {
				push(stack2, stack1.top().first);
				stack1.pop();
			}
		}
		if (!stack2.empty()) {
			stack2.pop();
		}
		push(stack1, elementCount[j]);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 

	int testCases;
	cin >> testCases; 
	while (testCases--) {
		int n, m;
		cin >> n >> m; 
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i]; 
		}

		cout << solve(n, m, arr) << endl; 
	}
	return 0;
}
