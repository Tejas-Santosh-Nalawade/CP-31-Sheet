#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        int mx=INT_MIN;
        for(int i=1;i<=n;i++)mx=max(mx,a[i]-b[i]);
        int c=0;
        for(int i=1;i<=n;i++)c+=(a[i]-b[i]==mx);
        cout<<c<<"\n";
        for(int i=1;i<=n;i++)if(a[i]-b[i]==mx)cout<<i<<' ';
        cout<<"\n";
    }
}