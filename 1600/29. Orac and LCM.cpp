#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);


		const int NMAX = (int)(3e5);
		bitset<NMAX / 2> bits;      
		bits.set();                
		vector<int> primes = {2};  
		for (int i = 3; i / 2 < (int)bits.size(); i = 2 * bits._Find_next(i / 2) + 1) {
				primes.push_back(i);  
				for (long long j = 1LL * i * i / 2; j < (int)bits.size(); j += i) bits[(size_t)j] = 0;
		}

		int n;
		cin >> n;

		unordered_map<int, int> cnt_prime;
		unordered_map<int, vector<int>> cnt_pair_prime;

		for (int i = 0; i < n; i++) {
				int x;
				cin >> x;

				for (int p : primes) {
						if (1LL * p * p > x) break;
						if (x % p != 0) continue;

						int e = 0;              
						while (x % p == 0) {
								++e;
								x /= p;
						}
						++cnt_prime[p];
						auto &vec = cnt_pair_prime[p];
						vec.push_back(e);
						sort(vec.begin(), vec.end());
						if (vec.size() > 2) vec.pop_back(); 
				}

				if (x > 1) {
						++cnt_prime[x];
						auto &vec = cnt_pair_prime[x];
						vec.push_back(1);
						sort(vec.begin(), vec.end());
						if (vec.size() > 2) vec.pop_back();
				}
		}
		ll ans = 1;
		for (int p : primes) {
				if (cnt_prime[p] < n - 1) continue;

				int e = 0;
				const auto it = cnt_pair_prime.find(p);
				if (it != cnt_pair_prime.end()) {
						const auto &vec = it->second; 
						e = (cnt_prime[p] == n ? vec[1] : vec[0]);
				}

				while (e--) ans *= p;
		}

		cout << ans << '\n';
		return 0;
}
