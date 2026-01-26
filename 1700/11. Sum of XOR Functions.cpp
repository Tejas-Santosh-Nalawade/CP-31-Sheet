#include<bits/stdc++.h>
using namespace std;
#define int long long

int M = 998244353;


int fun(vector<int> a){
    int n = a.size();
    int pref[n + 1];
    pref[0] = 0;
    for (int i = 1; i <= n; i++){
        pref[i] = a[i - 1];
        pref[i] ^= pref[i - 1];
    }

    int ans = 0;
    int c0 = 0, c1 = 0, s0 = 0, s1 = 0;

    for (int i = 0; i <= n; i++){

        if (pref[i] == 1){
            ans += (c0 * i) % M - s0;
            ans %= M;
        }
        else{
            ans += (c1 * i) % M - s1;
            ans %= M;
        }


        c0 += pref[i] == 0;
        s0 += (pref[i] == 0) * i;
        c1 += pref[i] == 1;
        s1 += (pref[i] == 1) * i;

        s0 %= M;
        s1 %= M;
    }

    ans = (ans + M) % M;

    return ans;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int j = 0; j < 30; j++){
        vector<int> b;
        for (int i = 0; i < n; i++){
            b.push_back((a[i] & (1 << j)) > 0);
        }

        ans += ((1 << j) * fun(b)) % M;
        ans %= M;
    }

    cout << ans << '\n';

}
 