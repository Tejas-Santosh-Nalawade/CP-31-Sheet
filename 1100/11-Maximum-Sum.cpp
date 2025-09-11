#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;
        vector<ll>v(n);
        for (auto &it : v)cin >> it;
        sort(v.begin(), v.end());
        vector<ll>pre(n);
        pre[0] = v[0];
        for (int i = 1; i < n; i++) {
            pre[i] = v[i] + pre[i - 1];
        }
        ll ans = 0;
        for (int first = 0; first <= k; first++) {
            int second=k-first;
            int left=2*first;
            int right=n-second-1;
            ll sum=pre[right]-(left==0 ? 0 : pre[left-1]);
            ans=max(ans,sum);
        }
        cout<<ans<<"\n";
    }
}