#include <iostream>
#include <vector>

using namespace std;


void setIO(const string& filename = "") {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
}


void solve() {
	int n;
	cin >> n;
	vector<int> array(n);
	for (int& value : array) {
		cin >> value; 
		value %= 2; 
	}

	constexpr int MOD = 998244353;
	vector<int> dp(4); 
	vector<int> count(2); 
	int result = 0;
	for (int value : array) {
		vector<int> newDp = dp;
		for (int i = 0; i < 2; ++i) {
			int j = i ^ value;
			dp[j | (value << 1)] += newDp[i | (j << 1)]; 
			result = (result + newDp[i | (j << 1)]) % MOD;
		}

		dp[0 | (value << 1)] = (dp[0 | (value << 1)] + count[0]) % MOD;
		dp[1 | (value << 1)] = (dp[1 | (value << 1)] + count[1]) % MOD;
		count[value]++;
	}
	cout << result << '\n'; 
}

int main() {
	setIO();
	int testCases = 1; 
	while (testCases--) {
		solve(); 
	}
	return 0; 
}