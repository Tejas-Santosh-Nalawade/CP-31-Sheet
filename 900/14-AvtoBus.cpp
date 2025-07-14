#include <iostream>
using namespace std;

int main() {
    int tt;
    cin >> tt;

    while (tt--) {
        long long n;
        cin >> n;

        if (n % 2 != 0 || n < 4) {
            cout << -1 << '\n';
            continue;
        }

        long long min_buses = (n + 5) / 6;
        long long max_buses = n / 4;

        cout << min_buses << ' ' << max_buses << '\n';
    }

    return 0;
}
