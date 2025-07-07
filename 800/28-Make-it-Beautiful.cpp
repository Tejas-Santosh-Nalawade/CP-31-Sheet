#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long max_number= a[n - 1];
        long long min_number = a[0];
        if(max_number == min_number)
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES" << "\n";
            cout<<max_number<<" ";
            for(int i=0; i<n-1; i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }
        return 0;

}
        