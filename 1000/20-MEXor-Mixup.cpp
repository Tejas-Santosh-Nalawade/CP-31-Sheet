#include <bits/stdc++.h>
using namespace std;

long long xor_till(long long n)
{
    long long a = n % 4;
    if (a == 0)
        return n;
    else if (a == 1)
        return 1;
    else if (a == 2)
        return n + 1;
    else
        return 0;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b;
        cin >> a >> b;
        long long arr_xor = xor_till(a - 1);

        if (arr_xor == b)
            cout << a << "\n";
        else if ((arr_xor ^ b) != a)
            cout << a + 1 << "\n";
        else
            cout << a + 2 << "\n";
    }
}