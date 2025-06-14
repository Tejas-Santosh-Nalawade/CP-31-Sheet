#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        if(c % 2==1){
            if(b>a){
                cout<<"Second"<<"\n";
            }
            else{
                cout<<"First"<<"\n";
            }
        }
        else{
            if(a>b){
                cout<<"First"<<"\n";
            }
            else{
                cout<<"Second"<<"\n";
            }
        }
    }
    return 0;
}