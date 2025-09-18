#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tt;
    cin>>tt;
    while(tt--){
        ll n,k;
        cin>>n>>k;
        ll arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        ll cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]!=arr[n-i-1][n-j-1]){
                    cnt++;
                }
            }
        }
        cnt/=2;
        if(cnt>k){
            cout<<"NO"<<"\n";
        }
        else{
            ll temp=k-cnt;
            if(temp%2==0)cout<<"YES"<<"\n";
            else{
                if(n%2==0)cout<<"NO"<<"\n";
                else cout<<"YES"<<"\n";
            }
        }
    }
}