#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s; 
	int n = (int)s.size(); 
	set<char> c; 
	int k;
	for (k = 0; k < n; k++) {
		if (c.find(s[k]) == c.end()) {
			c.insert(s[k]); 
		} else {
			break; 
		}
	}
	for (int i = k; i < n; i++) { 
		if (s[i] != s[i - k]) {
			cout << "NO" << endl; 
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