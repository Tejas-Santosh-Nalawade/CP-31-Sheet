#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) 
            cin >> a[i];

        int flag = 0;
        for (int j = 1; j < n - 1; j++) 
        {
            int i = -1;
            int k = -1;
            for (int left = 0; left < j; left++) 
            {
                if (a[left] < a[j])
                {
                    i = left;
                    break;
                }
            }
            for (int right = j + 1; right < n; right++)
            {
                if (a[right] < a[j])
                {
                    k = right;
                    break;
                }
            }
            if (i != -1 && k != -1)
            {
                cout << "YES" << endl;
                cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                flag = 1;
                break;
            }
        } 
        if (flag == 0)
            cout << "NO" << endl;
    }
    return 0;
}
