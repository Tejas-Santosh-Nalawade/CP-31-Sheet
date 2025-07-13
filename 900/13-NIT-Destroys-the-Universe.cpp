#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];


        int count_of_zero = 0;

        for (int i = 0; i < n; i++) 
        {
            if (a[i] == 0)
                count_of_zero++;
        }

        bool found_zero = false;
        int left = 0;
        int right = n - 1;

        while (a[left] == 0) 
            left++;
        while (a[right] == 0) 
            right--;

        for (int i = left; i <= right; i++) 
        {
            if (a[i] == 0)
                found_zero = true;
        }

        if (count_of_zero == n) 
            cout << 0 << endl;
        else if (found_zero == false)
            cout << 1 << endl;
        else 
            cout << 2 << endl;
    }
    return 0;
}