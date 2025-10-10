#include <bits/stdc++.h>

using namespace std;
int binSearch(vector<long long> &pmax, int n, int val)
{
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (pmax[mid] <= val)
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
		int n, q; 
		cin >> n >> q;

		vector<long long> steps(n), query(q); 
		for (int i = 0; i < n; i++)
			cin >> steps[i]; 
		for (int i = 0; i < q; i++)
			cin >> query[i];

		vector<long long> pmax(n), psum(n); 
		pmax[0] = steps[0];
		psum[0] = steps[0]; 
		for (int i = 1; i < n; i++)
		{
			pmax[i] = max(pmax[i - 1], steps[i]); 
			psum[i] = psum[i - 1] + steps[i]; 
		} 
		for (int i = 0; i < q; i++)
		{
			int val = query[i]; 
			int ind = binSearch(pmax, n, val);
			if (ind == -1)
			{
				cout << "0 ";
			}
			else
			{
				cout << psum[ind] << " "; 
			}
		} 

		cout << "\n"; 
	}

	return 0;
}

