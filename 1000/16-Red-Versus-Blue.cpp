#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, r, b;
        cin >> n >> r >> b;
        string s;
        int length_of_red = r / (b + 1);
        int extra_red = r % (b + 1);
        for (int times = 1; times <= b + 1; times++)
        {
            for (int i = 0; i < length_of_red; i++) 
                s += 'R';
            if (extra_red > 0)
            {
                s += 'R';
                extra_red--;
            }
            if (times != b + 1)
                s += 'B';
        }
        cout << s << "\n";
    }
    return 0;
}
