#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int tt;
    cin >> tt;
    while(tt--) { 
        int n;
        cin >> n; 
        vector<ll> v(n);
        for (int i = 0; i < n; i++) { 
            cin >> v[i];
        }
        ll gcd1 = 0, gcd2 = 0; 
        for (int i = 0; i < n; i++) { 
            if (i & 1) {
                gcd2 = __gcd(gcd2, v[i]); 
            } else {
                gcd1 = __gcd(gcd1, v[i]);
            }
        }
        bool flag = true;
        for (int i = 1; i < n; i += 2) {
            if (v[i] % gcd1 == 0) { 
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << gcd1 << endl; 
            continue;
        }
        flag = true;
        for (int i = 0; i < n; i += 2) {
            if (v[i] % gcd2 == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << gcd2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}