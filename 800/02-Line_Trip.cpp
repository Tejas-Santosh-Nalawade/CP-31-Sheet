#include <bits/stdc++.h>
using namespace std;

void minimumPossibleVolume(vector<long long>&gasStation)
{
    int n = gasStation.size();
    long long max_distance_between_point = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            max_distance_between_point = max(max_distance_between_point, 2 * (gasStation[i] - gasStation[i - 1]));
        } 
        else    
        {
            max_distance_between_point = max(max_distance_between_point, gasStation[i] - gasStation[i - 1]);
        }
    }
    cout << max_distance_between_point << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        // Input
        long long n, x;
        cin >> n >> x;
        vector<long long> gasStation(n);
        gasStation.push_back(0);
        for (int i = 0; i < n; i++)
        {
            long long point;
            cin >> point;
            gasStation.push_back(point);
        }
        gasStation.push_back(x);
        // Function minimum Possible volume
        minimumPossibleVolume(gasStation);
    }

    return 0;
}