
#include<bits/stdc++.h>

using namespace std;
const int NMAX = 2e5+5;
int dp[NMAX], id[NMAX];
vector<pair<int,int>> edg[NMAX];
void dfs(int u){
    for(auto it : edg[u]){
        if(dp[it.first] == 0){
            dp[it.first] = dp[u] + (it.second <= id[u]);
            id[it.first] = it.second;
            dfs(it.first);
        }
    }
}
void tc(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) dp[i] = id[i] = 0, edg[i].clear();
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        edg[u].push_back({v,i});
        edg[v].push_back({u,i});
    }
    dp[1] = 1;
    dfs(1);
    int ans = 0;
    for(int i=1; i<=n; i++) ans=max(ans,dp[i]);
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin>>tt;
    while(tt--)
        tc();
    return 0;
}