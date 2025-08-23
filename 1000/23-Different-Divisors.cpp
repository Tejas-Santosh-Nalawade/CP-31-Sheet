#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> primes;
    for (long long i = 2; i <= 100000; i++) 
    {
        bool is_prime = true;
        for (long long j = 2; j * j <= i; j++) 
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            primes.push_back(i);
    }

    
    int t;
    cin >> t;

    while (t--) 
    {
        long long d;
        cin >> d;

        long long p = -1;
        for (long long i = 0; i < primes.size(); i++)
        {
            if (primes[i] >= (1 + d))
            {
                p = primes[i];
                break;
            }
        }
        long long q = -1;
        for (long long i = 0; i < primes.size(); i++) 
        {
            if (primes[i] >= (p + d))
            {
                q = primes[i];
                break;
            }
        }

        long long a = min(1LL * p * p * p, 1LL * p * q);
        cout << a << "\n";
    }
}
