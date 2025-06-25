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
       string s;
       cin>>s;

       long long ans =n;
       long long left =0, right = n-1;
       while(left<=right){
            if(s[left] !=s[right]){
                ans-=2;
            }
            else{
                break;
            }
            left++;
            right--;
       }
       cout<<ans<<"\n";
    }
    return 0;

}