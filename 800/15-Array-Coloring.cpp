#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
    {
        long long  n;
        cin>>n;
        long long a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        long long count_odd = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 1)
                count_odd++;
        }
        if(count_odd %2 == 1){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
    }

    return 0;
}