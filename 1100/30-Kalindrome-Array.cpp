#include <bits/stdc++.h>
using namespace std;

#define ll long long


bool check(vector<ll>& a, int x) {
	int n = a.size();
	vector<ll> b;

    for (int i = 0; i < n; i++) {
		if (a[i] != x) {
			b.push_back(a[i]);
		}
	}
	int m = b.size();

    for (int i = 0; i < m; i++) {
		if (b[i] != b[m - i - 1]) {
			return false; 
            
		}
	}
	return true;
    
}


void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);

    for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

    for (int i = 0; i < n / 2; i++) {
		if (a[i] != a[n - i - 1]) {
            if (check(a, a[i]) || check(a, a[n - i - 1])) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
			return;
		}
	}
	cout << "YES" << endl; 
}

int main() {
	int tt = 1;
	cin >> tt;

    while (tt--) {
		solve();
	}
}
