# include<bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        if(n==1 || (n-1)%3==0 || (n+1) %3 ==0)
        {
            cout<<"First"<<"\n";
        }
        else{
            cout<<"Second"<<"\n";
        }
    }
    return 0;
}