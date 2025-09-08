#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    vector<ll>pre(n);
    pre[0]=v[0];
    for(ll i=1;i<n;i++){//n
        pre[i]=v[i]+pre[i-1];
    }
    ll ans=0;
    for(ll k=1;k<=n;k++){
        if(n%k)continue;
        ll start=k-1;
        ll res=0;
        ll maxi=pre[start];
        ll mini=pre[start];
        for(ll idx=start+k;idx<n;idx+=k){
            ll curr=pre[idx]-pre[idx-k];
            maxi=max(maxi,curr);
            mini=min(mini,curr);
        }
        ans=max(ans,maxi-mini);
    }
    cout<<ans<<endl;
}



int main() {
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}