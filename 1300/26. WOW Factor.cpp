#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
#define endl '\n'

int main() {
    fastio();

    string s;
    cin >> s;
    ll a = 0, b = 0, c = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'o') b+=a;
        else if (i > 0 &&  s[i-1] == 'v'){
            a++;
            c+=b;
        } 

    }
    cout << c << endl;
    return 0;
}