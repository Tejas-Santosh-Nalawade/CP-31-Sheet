#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        long long count_of_3 = 0;
        long long count_of_2 = 0;

        while (n > 0 && n % 3 == 0) 
        {
            count_of_3++;
            n /= 3;
        }

        while (n > 0 && n % 2 == 0) 
        {
            count_of_2++;
            n /= 2;
        }

        if (n > 1 || count_of_2 > count_of_3)
            cout << -1 << "\n";
        else
            cout << count_of_3 + (count_of_3 - count_of_2) << endl;
    }
    return 0;
}