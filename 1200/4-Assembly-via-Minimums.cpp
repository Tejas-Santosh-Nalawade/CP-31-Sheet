#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt; 

	while (tt--) {
		int n;
		cin >> n;


		int m = (n * (n - 1)) / 2;

		vector<int> v(m); 
		for (int i = 0; i < m; i++)
			cin >> v[i];

		sort(v.begin(), v.end());

		int x = n - 1, i = 0; 
		while (x > 0) {
			cout << v[i] << " "; 
			i += x;
			x--;
		}

		cout << "1000000000\n";
	}

	return 0;
}
