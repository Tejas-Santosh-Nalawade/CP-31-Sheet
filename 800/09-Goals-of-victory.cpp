#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long tt;
    cin>>tt;
    while(tt--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
        }
        long long sum = 0;
        for(int i=0; i<n;  i++)
        {
            sum +=a[i];
        }
        cout<<(-sum)<<"\n";
        
    }
    return 0;
}