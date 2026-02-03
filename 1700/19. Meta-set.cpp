#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<int>> sequences;

vector<int> calculateComplement(const vector<int>& a, const vector<int>& b) {
	vector<int> complement(k);
	for (int i = 0; i < k; i++) {
		complement[i] = (6 - (a[i] + b[i])) % 3;
	}
	return complement;
}

void solve() {
	cin >> n >> k;
	sequences.resize(n);
	for (auto& sequence : sequences) {
		sequence.resize(k);
		for (auto& element : sequence) {
			cin >> element;
		}
	}

	map<vector<int>, int> complementCount;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			auto complement = calculateComplement(sequences[i], sequences[j]);
			complementCount[complement]++;
		}
	}

	long long result = 0;
	for (auto& sequence : sequences) {
		result += static_cast<long long>(complementCount[sequence]) * (complementCount[sequence] - 1) / 2;
	}

	cout << result << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	
	int testCases = 1;
	while (testCases--) {
		solve();
	}
	
	return 0;
}
