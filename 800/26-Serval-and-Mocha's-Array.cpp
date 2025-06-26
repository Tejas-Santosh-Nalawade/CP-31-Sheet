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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if(__gcd(a[i],a[j]) <=2){
                    flag = 1;
                }
            }
        }

        if(flag == 0){
            cout<<"No"<<"\n";
        }
        else{
            cout<<"Yes"<<"\n";
        }
    }
    return 0;
}