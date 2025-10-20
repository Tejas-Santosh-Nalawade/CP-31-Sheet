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

		string s;
		cin >> s;

		int ans = INT_MAX;

		for (char c = 'a'; c <= 'z'; c++)
		{
			int tmp = 0;
			bool isPoss = true; 

			int i = 0, j = n - 1; 

			while (i < j)
			{
				if (s[i] == s[j])
				{
					i++; 
					j--;
					continue;
				}

				if (s[i] == c)
				{
					tmp++;
					i++; 
				}
				else if (s[j] == c)
				{
					tmp++;
					j--;
				}
				else
				{
					isPoss = false;
					break;
				}
			} //? O(N)

			if (!isPoss)
				tmp = INT_MAX;

			ans = min(ans, tmp);
		}

		if (ans == INT_MAX)
			ans = -1;

		cout << ans << "\n";
	}

	return 0;
}
