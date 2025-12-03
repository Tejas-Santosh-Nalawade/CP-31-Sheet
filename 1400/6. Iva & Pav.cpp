#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
 
const int N =200003;
const int bits=30;
int pref[N][bits];
int a[N];
void Buildprefix(int n){
    for(int i=0; i< n; i++){
        for(int j=0; j<30; j++){
            if(a[i]&(1<<j)){
                pref[i+1][j]=pref[i][j]+1;
            }
            else{
                pref[i+1][j]=pref[i][j];
            }
        }
    }
}
void solve(){
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        cin >> a[i];
    }
    Buildprefix(n);
    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        if(a[l-1]<k){
            cout << -1 << '\n';
            continue;
        }
        int lo=l;
        int hi=n;
        int ans=l;
        while(lo<=hi){
            int s=(lo+hi)/2;
            int num=0;
            for(int j=0; j< bits; j++){
                if(pref[s][j]-pref[l-1][j]==s-l+1){
                    num+=(1<<j);
                }
            }
            if(num>=k){
                lo=s+1;
                ans=max(ans, s);
            }
            else hi=s-1;
        }
        cout << ans << '\n';
    }
}
 
int main(){
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}