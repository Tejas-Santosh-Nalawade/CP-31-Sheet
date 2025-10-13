#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;

	while (tt--) {
		int n, m;
		cin >> n >> m; 
		vector<int> v(m);
		for (int i = 0; i < m; i++)
			cin >> v[i];

		sort(v.begin(), v.end());

		vector<int> gaps;
		for (int i = 0; i < m - 1; i++) {
			gaps.push_back(v[i + 1] - v[i] - 1); 
		}

		gaps.push_back(v[0] + n - v[m - 1] - 1); 

		sort(gaps.rbegin(), gaps.rend());

		int numSaved = 0, numDays = 0; 

		for (auto gap : gaps) {
			int currGap = gap - numDays * 2; 
			if (currGap > 0) {
				numSaved++;

				currGap -= 2; 
				if (currGap > 0)
					numSaved += currGap;

				numDays += 2; 
			}
		}

		cout << (n - numSaved) << "\n"; 
	}

	return 0;
}
