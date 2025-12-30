#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k1, k2;
	cin >> n >> k1 >> k2;

	vector<int> a(n), b(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		pq.push(abs(a[i] - b[i]));
	}

	int k = k1 + k2;
	while (k > 0) {
		int x = pq.top();
		pq.pop();

		if (x == 0) break; 

		--k;
		--x;
		pq.push(x);
	}

	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top() * pq.top(); 
		pq.pop();
	}
	if (k % 2) ++ans;

	cout << ans << '\n';
	return 0;
}