#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ok[n];
	for (int i = 0; i < n - 1; i++) {
		ok[i] = (a[i] < 2 * a[i + 1]);
	}
	int tot = 0;
	for (int i = 0; i < k; i++) {
		tot += ok[i];
	}
	int res = 0;
	if (tot == k) {res++;}
	for (int i = k; i < n - 1; i++) {
		tot += ok[i];
		tot -= ok[i - k];
		if (tot == k) {res++;}
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
}