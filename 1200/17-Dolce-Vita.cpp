#include <bits/stdc++.h>

using namespace std;

bool pf(long long val, int ind, int x, int mid)
{
	if (val + (1LL * (ind + 1) * (mid - 1)) <= x)
		return true;
	return false;
}

int binSearch(long long val, int ind, int x)
{
	int low = 1, high = 1e9 + 5;
	int ans = 0;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (pf(val, ind, x, mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	} 

	return ans;
} 

int main()
{
	int tt;
	cin >> tt;

	while (tt--)
	{
		int n, x;
		cin >> n >> x;

		vector<int> cost(n);
		for (int i = 0; i < n; i++)
			cin >> cost[i];

		sort(cost.begin(), cost.end());

		vector<long long> presum(n);

		presum[0] = cost[0];
		for (int i = 1; i < n; i++)
		{
			presum[i] = presum[i - 1] + cost[i];
		} 

		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += binSearch(presum[i], i, x);
		} 

		cout << ans << "\n";
	}

	return 0;
}

