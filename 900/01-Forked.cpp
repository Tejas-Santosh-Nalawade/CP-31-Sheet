#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b;
        cin >> a >> b;
        long long x_king, y_king;
        cin >> x_king >> y_king;
        long long x_queen, y_queen;
        cin >> x_queen >> y_queen;

        set<pair<int,int>> king_hits, queen_hits;

        for(int j = 0; j < 4; j++){ 
            king_hits.insert({x_king+dx[j]*a, y_king+dy[j]*b});
            king_hits.insert({x_king+dx[j]*b, y_king+dy[j]*a});

            queen_hits.insert({x_queen+dx[j]*a, y_queen+dy[j]*b});
            queen_hits.insert({x_queen+dx[j]*b, y_queen+dy[j]*a});
        }

        int ans = 0;
        for(auto position : king_hits) 
            if(queen_hits.find(position) != queen_hits.end())
                ans++;
        
        cout << ans <<"\n";
    }
    return 0;
}