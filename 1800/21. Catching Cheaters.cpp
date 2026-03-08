#include <bits/stdc++.h>
using namespace std;

#define INF (int)(1e9)

const int maxn = 5005;
int dp[maxn][maxn];

void Solve() 
{
    int n, m;
    cin>>n>>m;
    string s1, s2;
    cin>>s1>>s2;
    
    int ans = 0;
    
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            if (i==0 && j==0)continue;
            dp[i][j] = 0;
            if (i!=0 && j!=0 && s1[i-1]==s2[j-1])
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2);
            if (i!=0)
            dp[i][j] = max(dp[i][j], dp[i-1][j] - 1);
            if (j!=0)
            dp[i][j] = max(dp[i][j], dp[i][j-1] - 1);
            
            ans = max(ans, dp[i][j]);
        }
    }
    
    cout<<ans;
}


int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        Solve();
    }
    return 0;
}