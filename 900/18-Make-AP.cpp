#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        bool answer = false;

        long long new_a = 2 * b - c; 
        if (new_a / a > 0 && new_a % a == 0) 
            answer = true;

        long long new_b = (a + c) / 2;
        if (new_b / b > 0 && new_b % b == 0 && (c - a) % 2 == 0)
            answer = true;

        long long new_c = 2 * b - a;
        if (new_c / c > 0 && new_c % c == 0)
            answer = true;

        if (answer)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
