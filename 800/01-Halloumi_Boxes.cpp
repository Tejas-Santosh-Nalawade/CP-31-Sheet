#include <bits/stdc++.h>
using namespace std;

void halloumi_box(int n, int k,vector<long long>&box)
{
    vector<long long> copy_box = box;
    sort(copy_box.begin(), copy_box.end());
    if(copy_box == box || k > 1)
    {
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> box(n);
        for (int i = 0; i < n; i++)
        {
            cin >> box[i];
        }
        halloumi_box(n, k,box);
    }
    return 0;
}