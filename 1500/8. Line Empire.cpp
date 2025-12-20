#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "\n"
const lol inf=1e18+8;
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
cin>>_;
while(_--)
{
    int n;
    lol a,b;
    cin>>n>>a>>b;
    vector<lol> x(n+1),p(n+1);
    x[0]=0;
    for(int i=1;i<=n;i++)   cin>>x[i];
    partial_sum(x.begin(),x.end(),p.begin());
    lol ans=inf;
    for(int i=0;i<=n;i++)
    {
        ans=min(ans,(a+b)*(x[i]-x[0])+b*(p[n]-p[i]-(n-i)*x[i]));
    }
    cout<<ans<<endl;
}
return 0;
}
