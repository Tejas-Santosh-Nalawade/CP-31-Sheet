#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        int i = 1;
        while (n % i == 0) 
            i++;
        cout << i - 1 << "\n";
    }
    return 0;
}