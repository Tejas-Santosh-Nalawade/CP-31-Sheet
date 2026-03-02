#include<bits/stdc++.h>
using namespace std;


using ll = long long;
const ll INF = (long long)4e14; 

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> up(n, vector<ll>(m)), down(n, vector<ll>(m));
    vector<vector<ll>> right(n, vector<ll>(m)), left(n, vector<ll>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            ll x;
            cin >> x;
            right[i][j] = x;      
            left[i][j + 1] = x;  
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            down[i][j] = x;       
            up[i + 1][j] = x;     
        }
    }

    if (k % 2 != 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << -1 << " ";
            }
            cout << "\n";
        }
        return;
    }

    k /= 2;
    vector<vector<vector<ll>>> dp(k + 1, vector<vector<ll>>(n, vector<ll>(m, INF)));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dp[0][i][j] = 0;

    for (int x = 1; x <= k; ++x) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0)
                    dp[x][i][j] = min(dp[x][i][j], dp[x - 1][i - 1][j] + down[i - 1][j]);
                if (i < n - 1)
                    dp[x][i][j] = min(dp[x][i][j], dp[x - 1][i + 1][j] + up[i + 1][j]);
                if (j > 0)
                    dp[x][i][j] = min(dp[x][i][j], dp[x - 1][i][j - 1] + right[i][j - 1]);
                if (j < m - 1)
                    dp[x][i][j] = min(dp[x][i][j], dp[x - 1][i][j + 1] + left[i][j + 1]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dp[k][i][j] * 2 << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    while (test_cases--) {
        solve();
    }

    return 0;
}