#include<bits/stdc++.h>
using namespace std;

void fillWater(int n, string &s)
{

        bool continous_three_empty_space = false;
        int total_count_empty_cell = 0;
        for(int i=0; i<n ; i++)
        {   
            if(s[i] == '.' && i + 1 < n && s[i+ 1] == '.' && i + 2 < n && s[i + 2] == '.')
            {
                continous_three_empty_space = true;
                break;
            }
            if(s[i] == '.')
            {
                total_count_empty_cell++;
            }
        }
        if(continous_three_empty_space)
        {
            cout<<2<<"\n";
        }
        else{
            cout<<total_count_empty_cell<<"\n";
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        fillWater(n, s);
    }
    return 0;
}
