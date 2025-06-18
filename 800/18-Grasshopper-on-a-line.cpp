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
        long long x , k;
        cin>>x>>k;
        if(x % k == 0){
            cout<< 2 <<"\n";
            cout<< 1 <<" "<< x-1 <<"\n";
        } 
        else{
            cout<<1<<"\n";
            cout<<x<<"\n";
        }
    }
    return 0;
}