#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll n,q;
        cin>>n>>q;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll>x(q);
        for(int i=0;i<q;i++){
            cin>>x[i];
        }
        ll prev=31;
        for(int i=0;i<q;i++){//q
            if(x[i]>=prev)continue;
            ll val=pow(2,x[i]);
            for(int j=0;j<n;j++){
                if(a[j]%val==0){
                    a[j]+=(val/2);
                }
            }
            prev=x[i];
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    
}