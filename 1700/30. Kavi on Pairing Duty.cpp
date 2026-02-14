#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 10;
const int MODULO = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	cin >> num;

	vector<int> divisor_count(MAX_N, 0);
	int cumulative_sum = 1;

	for (int i = 1; i <= num; ++i) {
		for (int j = i + i; j <= num; j += i) {
			divisor_count[j]++;
		}
	}

	divisor_count[0] = cumulative_sum;

	for (int i = 1; i <= num; ++i) {
		divisor_count[i] = (divisor_count[i] + cumulative_sum) % MODULO;
		cumulative_sum = (cumulative_sum + divisor_count[i]) % MODULO;
	}

	cout << divisor_count[num] << endl;
	return 0;
}
