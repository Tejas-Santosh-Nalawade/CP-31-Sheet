#include <bits/stdc++.h>
using namespace std;

int main()
{

  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--){
    
        long long n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
 
        long long count_of_zeroes = 0;
        long long maximum_length = 0;
        for (int i = 0; i < n; i++) 
        {
            if (a[i] == 0)
                count_of_zeroes++; 
            else
                count_of_zeroes = 0; 
            
            maximum_length = max(maximum_length, count_of_zeroes);
        }
        cout << maximum_length << "\n";
    }
    return 0;

}