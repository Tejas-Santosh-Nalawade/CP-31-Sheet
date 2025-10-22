#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, k, x;
	cin >> n >> k >> x;

	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];


	sort(v.begin(), v.end());


	vector<long long> differences;

	for (int i = 0; i < n - 1; i++)
	{
		if (v[i + 1] - v[i] > x)
		{
			differences.push_back(v[i + 1] - v[i]);
		}
	}

	sort(differences.begin(), differences.end()); 
	int ans = differences.size() + 1;

	for (auto difference : differences)
	{
		long long val = (difference / x) + (difference % x != 0) - 1; 
		if (k >= val)
		{
			ans--;
			k -= val;
		}
	}
	cout << ans << "\n";
}

