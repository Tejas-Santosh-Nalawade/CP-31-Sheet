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
        long long n;
        cin>>n;
        long long a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        long long total_xor = 0;

        for(int i=0; i<n; i++){
                total_xor ^= a[i];
        }

        if(n % 2 == 1){
            cout<<total_xor<<"\n";
        }

        else{
            if(total_xor  == 0){
                cout<<total_xor<<"\n";
            }
            else{
                cout<<-1<<"\n";
            }
        }
    }
    return 0;

}