#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define MOD1 998244353

typedef long long ll;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


ll mod_multiply(ll a, ll b, ll mod) {
	return ((a % mod) * (b % mod)) % mod;
}

void solve() {
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		ll n, k;
		cin >> n >> k;

		vector<ll> a(n), b(k), index(n + 1), occ(n, 1);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			index[a[i]] = i;
		}

		for (int i = 0; i < k; i++) {
			cin >> b[i];
		}
		reverse(b.begin(), b.end()); 

		ll answer = 1; 
	
		for (int i = 0; i < k; i++) {
			int current_index = index[b[i]]; 
			occ[current_index]--; 


			int left = current_index > 0 ? occ[current_index - 1] : 0;
			int right = current_index < n - 1 ? occ[current_index + 1] : 0;

	
			answer = mod_multiply(answer, left + right, MOD1);
		}

		cout << answer << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve(); 

	return 0;
}
