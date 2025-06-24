#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long tt;
    cin >> tt;
      while (tt--)
    {
        int source_x, source_y, destination_x, destination_y;
        cin >> source_x >> source_y >> destination_x >> destination_y;
        if (destination_y < source_y)
        {
            cout << -1 << "\n";
            continue;
        }
        int moves = destination_y - source_y;
        source_x += moves;
        if (source_x < destination_x)
        {
            cout << -1 << "\n";
            continue;
        }
        moves += (source_x - destination_x);
        cout << moves << "\n";
    }
    return 0;
}