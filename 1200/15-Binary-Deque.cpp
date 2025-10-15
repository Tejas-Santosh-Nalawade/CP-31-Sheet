#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tt;
	cin >> tt;

	while (tt--)
	{
		int n, s;
		cin >> n >> s; 

		vector<int> v(n);

		for (int i = 0; i < n; i++)
			cin >> v[i]; //? O(N)

		int len = -1; 

		map<int, int> mp;

		mp[0] = -1; 

		int sum = 0; 
		for (int i = 0; i < n; i++)
		{
			sum += v[i]; 
			if (mp.count(sum - s))
			{
				len = max(len, i - mp[sum - s]);
			}

			
			if (!mp.count(sum))
			{
				mp[sum] = i; 
			}
		} 
		if (len == -1)
		{
			cout << "-1\n";
		}
		else
		{
			
			cout << (n - len) << "\n";
		}
	}
}
