#include <bits/stdc++.h>
 
#define all(arr) arr.begin(), arr.end()
 
using namespace std;
 
const int MAXN = 200200;
 
int n, m;
string arr[MAXN];
int len[MAXN], zrr[MAXN];
 
void build() {
    memset(zrr, 0, sizeof(*zrr) * n);
    for (int i = 0; i < n; ++i) {
        len[i] = arr[i].size();
        for (auto it = arr[i].rbegin(); it != arr[i].rend() && *it == '0'; ++it) {
            ++zrr[i];
        }
    }
}
 
string solve() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += len[i] - zrr[i];
    }
    sort(zrr, zrr + n);
    reverse(zrr, zrr + n);
    for (int i = 0; i < n; ++i) {
        if (i & 1) ans += zrr[i];
    }
    return (ans - 1 >= m ? "Sasha" : "Anna");
}
 
int main() {
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        build();
        cout << solve() << '\n';
    }
}