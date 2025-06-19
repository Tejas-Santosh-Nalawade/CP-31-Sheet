#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin>>n;

        vector<int> a(n);

        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int positive_count = 0;    // 1 count 
        int negative_count = 0;    // -1 count

        for(int i=0; i<n; i++)
        {
            if(a[i] == 1){
                positive_count++;
            }
            else{
                negative_count++;
            }
        }
        int operations= 0;

        while(positive_count < negative_count || negative_count % 2 == 1){
            operations++;
            positive_count++;
            negative_count--;
        }
        cout<<operations<<"\n";
    }
    return 0;
}