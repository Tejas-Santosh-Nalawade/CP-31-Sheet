#include <bits/stdc++.h>

#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(time(nullptr));

const ll inf = 1e18;
const ll M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

void solve(int tc) {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m); 
	vector<int> op(n + 1); 
	vector<vector<int>> del(n + 1); 

	for (auto &e : a) {
		cin >> e.x >> e.y; 
		op[e.x]++;
		del[e.y].emplace_back(e.x); 
	}

	multiset<int> cur; 
	vector<int> dp(n + 1); 

	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];

		for (int j = 0; j < op[i]; ++j) cur.insert(i);

		if (!cur.empty()) {
			int min_l = *cur.begin();
			dp[i] = max(dp[i], dp[min_l - 1] + (int)cur.size());
		}

		for (int l : del[i]) {
			cur.erase(cur.find(l));
		}
	}

	cout << dp[n];
}

bool multi = true;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	if (multi) cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
		cout << "\n";
	}
	return 0;
}