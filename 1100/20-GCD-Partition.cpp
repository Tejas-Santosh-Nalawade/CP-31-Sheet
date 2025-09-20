#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	ll ans = 0; 
	ll total_sum = accumulate(v.begin(), v.end(), 0LL);
	ll sum = 0;

	
	for (int i = 0; i < n - 1; i++) {
		sum += v[i];
		ans = max(ans, __gcd(total_sum - sum, sum));
	}

	cout << ans << "\n";
}

int main() {
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve(); 
	}
}
