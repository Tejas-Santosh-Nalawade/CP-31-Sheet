#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        map<long long, long long> frequency_map;
        for(int i=0; i<n; i++)
        {
            frequency_map[a[i]]++;
        }
        if(frequency_map.size()>=3){
            cout<<"No"<<"\n";
        }
        else{ 
            // begin first Elemnent and rbegin last element
            long long freq_1 = frequency_map.begin()->second;
            long long freq_2 = frequency_map.rbegin()->second;
            if(freq_1 == freq_2)
            {
                cout<<"Yes"<<"\n";
            }
            else if(n % 2 ==1 && abs(freq_1 - freq_2) == 1){
                cout<<"Yes"<<"\n";
            }
            else{
                cout<<"No"<<"\n";
            }
        }
    }
    return 0;
}