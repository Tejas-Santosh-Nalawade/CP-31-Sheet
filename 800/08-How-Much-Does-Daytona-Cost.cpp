#include<bits/stdc++.h>
using namespace std;
// Aproach 1 checking each if found break
// int main()
// {
//     ios_base::sync_with_stdio(0); 
//     cin.tie(0);
//     cout.tie(0);
//     int tt;
//     cin>>tt;
//     while(tt--)
//     {
//         long long n,k;
//         cin>>n>>k;
//         vector<long long> subarray(n);
//         for(int i=0; i<n; i++)
//         {
//             cin>>subarray[i];
//         }
//         bool check= false;
//         for(int i=0; i<n; i++)
//         {
//            if(subarray[i] == k)
//            {
//             check = true;
//             break;
//            } 
//         }
//         if(check)
//         {
//             cout<<"YES"<<"\n";
//         }
//         else{
//             cout<<"NO"<<"\n";
//         }
//     }
//     return 0;
// }

// approach 2 using count


int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        long long n,k;
        cin>>n>>k;
        vector<long long> subarray(n);
        for(int i=0; i<n; i++)
        {
            cin>>subarray[i];
        }
        if(count(subarray.begin(),subarray.end(),k)>0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}