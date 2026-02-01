#include<bits/stdc++.h>

using namespace std;
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

const ll INF = 1e17; 
const ll MAXM = 1e5;
vector<ll> factors[MAXM + 5]; 
void initialize_factors() {
	for (ll i = 1; i <= MAXM; ++i) {
		for (ll j = i; j <= MAXM; j += i) {
			factors[j].push_back(i); 
		}
	}
}

void solve() {
	ll n, m;
	cin >> n >> m; 
	vector<pii> values; 
	for (ll i = 0; i < n; ++i) {
		ll value;
		cin >> value; 
		values.push_back({value, i}); 
	}
	
	sort(values.begin(), values.end()); 
	vector<ll> frequency(m + 5, 0); 
	ll count_factors = 0; 
	ll left_index = 0; 
	ll min_difference = INF; 

	for (ll right_index = 0; right_index < n; ++right_index) {
		for (auto factor : factors[values[right_index].first]) {
			if (factor > m) break; 
			if (!frequency[factor]++) {
				++count_factors; 
			}
		}
		
		while (count_factors == m) {
			ll current_difference = values[right_index].first - values[left_index].first; 
			if (current_difference < min_difference) {
				min_difference = current_difference; 
			}
			for (auto factor : factors[values[left_index].first]) {
				if (factor > m) break;
				if (--frequency[factor] == 0) {
					--count_factors; 
				}
			}
			++left_index; 
		}
	}

	cout << (min_difference >= INF ? -1 : min_difference) << "\n";
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	
	initialize_factors(); 
	
	ll test_cases;
	cin >> test_cases;
	while (test_cases--) {
		solve(); 
	}
	
	return 0;
}
