#include <bits/stdc++.h>
using namespace std;

int main()
{

  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long tt;
    cin >> tt;
    while (tt--){
        long long n,k;
        cin>>n>>k;
        if(n%2 ==0 || (n-k) % 2 == 0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;

}