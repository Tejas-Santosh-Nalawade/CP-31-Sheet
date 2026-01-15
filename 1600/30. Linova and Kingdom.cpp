#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>> adj;  
    vector<int> d;             
vector<int> s;             
vector<int> v;              
void dfs(int x, int p) {
	for (int y : adj[x]) {
		if (y == p) continue;                 
		d[y] = d[x] + 1;                      
		dfs(y, x);
		s[x] += s[y] + 1;                     
	}
	v[x] = d[x] - s[x];                        
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	adj.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;                            
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	d.assign(n, 0);
	s.assign(n, 0);
	v.assign(n, 0);
	dfs(0, -1);                              

	sort(v.rbegin(), v.rend());          
	long long ans = accumulate(v.begin(), v.begin() + k, 0LL);
	cout << ans << '\n';

	return 0;
}
