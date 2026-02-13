#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 200001;
const int MOD = 1000000007;

vector<long long> factorial(MAX_SIZE), inverse(MAX_SIZE), inverseFactorial(MAX_SIZE);
vector<vector<int>> memo(MAX_SIZE, vector<int>(2));
vector<vector<int>> visited(MAX_SIZE, vector<int>(2));
int currentTestId = 0;
int evenCount, twoPowerN, arraySize;

void precomputeFactorials() {
	factorial[0] = inverse[1] = factorial[1] = inverseFactorial[0] = inverseFactorial[1] = 1;
	for (long long i = 2; i < MAX_SIZE; i++) {
		factorial[i] = (factorial[i - 1] * i) % MOD;
		inverse[i] = MOD - (inverse[MOD % i] * (MOD / i) % MOD);
		inverseFactorial[i] = (inverse[i] * inverseFactorial[i - 1]) % MOD;
	}
}

int addModulo(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

long long multiplyModulo(int x, int y) {
	return (1LL * x * y) % MOD;
}

long long combination(int n, int r) {
	if (r > n) return 0;
	return multiplyModulo(multiplyModulo(factorial[n], inverseFactorial[r]), inverseFactorial[n - r]);
}

int solve(int index, bool equal) {
	if (index < 0) return 1;
	int& result = memo[index][equal];
	if (visited[index][equal] == currentTestId) return result;
	visited[index][equal] = currentTestId;
	if (!equal) return result = multiplyModulo(twoPowerN, solve(index - 1, 0));
	if (arraySize & 1) return result = multiplyModulo(solve(index - 1, 1), addModulo(evenCount, 1));
	return result = addModulo(multiplyModulo(solve(index - 1, 1), evenCount), solve(index - 1, 0));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	precomputeFactorials();

	int testCases;
	cin >> testCases;
	while (testCases--) {
		currentTestId++;
		int length;
		cin >> arraySize >> length;
		evenCount = 0;
		for (int i = 0; i < arraySize; i += 2) {
			evenCount = addModulo(evenCount, combination(arraySize, i));
		}
		twoPowerN = 1;
		for (int i = 0; i < arraySize; i++) {
			twoPowerN = multiplyModulo(twoPowerN, 2);
		}
		cout << solve(length - 1, true) << endl;
	}

	return 0;
}
