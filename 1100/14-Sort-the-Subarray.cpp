#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
int main()
{
    ll tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        ll arr[n];
        ll arr2[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        int change1=-1,change2=-1;
        for(int i=0;i<n;i++){
            if(arr[i]!=arr2[i]){
                if(change1==-1){
                    change1=i;
                }
                else{
                    change2=i;
                    break;
                }
            }
        }
        int i=change1-1;
        while(i>=0){
            if(arr2[i]<=arr2[i+1]){
                i--;
            }
            else{
                break;
            }
        }
        change1=i+1;
        if(change2==-1){
            change2=n-1;
        }
        int j=change2+1;
        while(j<n){
            if(arr2[j]>=arr2[j-1]){
                j++;
            }
            else{
                break;
            }
        }
        change2=j-1;
        cout<<change1+1<<" "<<change2+1<<"\n";
    }
}