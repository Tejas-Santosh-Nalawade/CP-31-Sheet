#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)(1e9+7)
void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin>>b[i];
    }
    sort(b.rbegin(), b.rend());
    ll result = 1;
    for (int i = 0; i < n; i++) {
        ll temp=upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll count = a.size() - temp;
        result = result * max(count - i, 0LL) % MOD;
    }
    cout << result << "\n";
}

int main() {
    int tt= 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}