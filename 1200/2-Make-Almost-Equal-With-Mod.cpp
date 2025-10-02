#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;

	while (tt--) { 
		int n;
		cin >> n;

		long long arr[n];

		for (int i = 0; i < n; i++)
			cin >> arr[i]; 

		long long ans = 0;


        for (int i = 1; i <= 60; i++) { 
            


            set<long long> distinctVals;
			long long k = 1LL << i;
            

			for (int ind = 0; ind < n; ind++) {
				distinctVals.insert(arr[ind] % k);
			}

			if (distinctVals.size() == 2) {
				ans = k;
				break;
			}
		} 

		cout << ans << "\n";
	}
}
