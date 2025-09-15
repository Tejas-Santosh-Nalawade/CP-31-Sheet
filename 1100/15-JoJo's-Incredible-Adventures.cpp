#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    int maxi=0;
    int i=0;
    while(i<n){
        if(s[i]=='0'){
            i++;
            continue;
        }
        int j=i+1;
        while(j<n && s[j]=='1'){
            j++;
        }
        maxi=max(maxi,j-i);
        i=j;
    }
    if(maxi==n){
        cout<<n*n<<"\n";
        return;
    }
    if(s[0]=='1' && s[n-1]=='1'){
        int i=0;
        int cnt=0;
        while(i<n && s[i]=='1'){
            i++;
            cnt++;
        }
        int j=n-1;
        while(j>i && s[j]=='1'){
            j--,cnt++;
        }
        maxi=max(maxi,cnt);
    }
    maxi++;
    ll temp=(maxi+1)/2;
    cout<<(temp)*(maxi/2)<<"\n";
}

int main(){
    int tt=1;
    cin>>tt;
    while(tt--){
        solve();
    }
} 