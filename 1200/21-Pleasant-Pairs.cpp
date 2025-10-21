#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tt;
	cin >> tt; 

	while (tt--)
	{
		int n;
		cin >> n; 


		vector<pair<long long, long long>> v(n);

		for (int i = 0; i < n; i++)
		{
			cin >> v[i].first; 
			v[i].second = i + 1;
		}

		sort(v.begin(), v.end()); 

		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (v[i].first * v[j].first >= 2 * n)
					break;

				if (v[i].first * v[j].first == v[i].second + v[j].second)
					ans++;
			}
		} 
		cout << ans << "\n";
	}

	return 0;
}

