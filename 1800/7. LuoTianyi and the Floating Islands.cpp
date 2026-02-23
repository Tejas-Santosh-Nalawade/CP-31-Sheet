#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;
const int MAX_NODES = 200005;

std::vector<int> adjacencyList[MAX_NODES];
int subtreeSize[MAX_NODES];
int factorial[MAX_NODES], inverseFactorial[MAX_NODES];


int modularExponentiation(int base, int exp) {
	int result = 1;
	while (exp > 0) {
		if (exp % 2 == 1)
			result = static_cast<int>(1LL * result * base % MOD);
		base = static_cast<int>(1LL * base * base % MOD);
		exp /= 2;
	}
	return result;
}

int combination(int n, int k) {
	if (k < 0 || k > n) return 0;
	return static_cast<int>(1LL * factorial[n] * inverseFactorial[k] % MOD * inverseFactorial[n - k] % MOD);
}

void initializeCombinations(int limit) {
	factorial[0] = inverseFactorial[0] = 1;
	for (int i = 1; i <= limit; ++i) {
		factorial[i] = static_cast<int>(1LL * factorial[i - 1] * i % MOD);
	}
	inverseFactorial[limit] = modularExponentiation(factorial[limit], MOD - 2);
	for (int i = limit - 1; i >= 1; --i) {
		inverseFactorial[i] = static_cast<int>(1LL * inverseFactorial[i + 1] * (i + 1) % MOD);
	}
}

void depthFirstSearch(int node, int parent) {
	subtreeSize[node] = 1;
	for (int neighbor : adjacencyList[node]) {
		if (neighbor != parent) {
			depthFirstSearch(neighbor, node);
			subtreeSize[node] += subtreeSize[neighbor];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int numNodes, k;
	std::cin >> numNodes >> k;

	initializeCombinations(MAX_NODES - 1);


	for (int i = 0; i < numNodes - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);
	}

	depthFirstSearch(1, 0);

	if (k % 2 == 1) {
		std::cout << "1\n";
	} else {
		int result = 0;
		for (int i = 2; i <= numNodes; ++i) {
			int leftSubtreeNodes = subtreeSize[i];
			int rightSubtreeNodes = numNodes - subtreeSize[i];
			int numWays = static_cast<int>(1LL * combination(leftSubtreeNodes, k / 2) * combination(rightSubtreeNodes, k / 2) % MOD);
			result = (result + numWays) % MOD;
		}
		result = static_cast<int>(1LL * result * modularExponentiation(combination(numNodes, k), MOD - 2) % MOD);
		result = (result + 1) % MOD;
		std::cout << result << '\n';
	}

	return 0;
}