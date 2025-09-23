#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

int64 modmul(long long a, long long b){
    return ( (__int128)a * b ) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; if(!(cin>>tt)) return 0;
    const int64 INV6 = 166666668LL;
    const int64 MUL = 2022LL % MOD;
    while(tt--){
        long long n; cin>>n;
        long long a = n % MOD;
        long long a2 = modmul(a,a);
        long long val = ( (4 * a2) % MOD + (3 * a) % MOD - 1 ) % MOD;
        if(val < 0) val += MOD;
        long long ans = modmul(a, val);
        ans = modmul(ans, INV6);
        ans = modmul(ans, MUL);
        cout << ans % MOD << '\n';
    }
    return 0;
}