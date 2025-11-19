#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt; 
	cin >> tt;
	while (tt--) {
		int n; 
		cin >> n;
		int f = 0; 
		for (int i = 2; i * i <= n; i++) { 
			if (n % i == 0) { 
				int k = n / i; 
				cout << k << " " << n - k << endl;
				f = 1; 
				break; 
			}
		}
		if (f == 0) {
			cout << 1 << " " << n - 1 << endl;
		}
	}
}
