#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    long long a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    long long minimum_operation = INT_MAX;
    for(int i=0; i<n; i++)
    {
        minimum_operation = min(minimum_operation, abs(a[i]));
    }
    cout<<minimum_operation<<"\n";

    return 0;
}