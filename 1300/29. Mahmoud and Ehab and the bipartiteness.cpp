#include <bits/stdc++.h>
 
using namespace std;
 
int lev[100005];
vector<int> adj[100005];
int n;
 
void dfs(int x,int hi,int pa)
{
    int i;
    lev[x]=hi;
    for(i=0;i<adj[x].size();i++)
    {
        if(adj[x][i]==pa)
            continue;
        dfs(adj[x][i],hi+1,x);
    }
}
 
int main()
{
    cin >> n;
    int i;
    for(i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0,-1);
    long long odd=0;
    for(i=1;i<=n;i++)
        odd+=(lev[i]%2);
    cout << odd*(n-odd)-(n-1) << endl;
}