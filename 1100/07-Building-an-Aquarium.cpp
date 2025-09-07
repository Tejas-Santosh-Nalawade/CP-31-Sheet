#include <bits/stdc++.h>
using namespace std;
#define ll long long 
bool check(ll mid,vector<ll>&heights,ll x){
    ll units=0;
    int n=heights.size();
    for(int i=0;i<n;i++){
        if(heights[i]<mid){
            units+=(mid-heights[i]);
        }
    }
    return units<=x;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll n,x;
        cin>>n>>x;
        vector<ll>heights(n);
        for(int i=0;i<n;i++){
            cin>>heights[i];
        }
        ll si=1,ei=1e12,ans=-1;
        while(si<=ei){
            ll mid=si+(ei-si)/2;
            if(check(mid,heights,x)){
                ans=mid;
                si=mid+1;
            }
            else{
                ei=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
    
}