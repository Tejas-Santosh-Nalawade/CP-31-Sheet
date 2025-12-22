#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> x) {
    sort(x.begin(), x.end());
    return x[x.size() / 2] - x[(x.size() - 1) / 2] + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    cout << solve(x) * solve(y) << '\n';
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}