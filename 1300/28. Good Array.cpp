#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(MAX + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	long long sum = accumulate(a.begin(), a.end(), 0ll);
	
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		sum -= a[i];
		--cnt[a[i]];
		if (sum % 2 == 0 && sum / 2 <= MAX && cnt[sum / 2] > 0) {
			ans.push_back(i);
		}
		sum += a[i];
		++cnt[a[i]];
	}
	
	cout << ans.size() << endl;
	for (auto it : ans) cout << it + 1 << " ";
	cout << endl;
	
	return 0;
}