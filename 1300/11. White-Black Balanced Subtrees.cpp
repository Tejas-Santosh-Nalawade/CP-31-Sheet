#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<int> child[n + 7];
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		child[x].push_back(i);
	}
	string s;
	cin >> s;
	int res = 0;
	function<int(int)> dp = [&] (int x) {
		int bal = (s[x - 1] == 'B') ? -1 : 1;
		if (child[x].empty()) {return bal;}
		for (int i : child[x]) {
			bal += dp(i);
		}
		if (bal == 0) {res++;}
		return bal;
	};
	dp(1);
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
}