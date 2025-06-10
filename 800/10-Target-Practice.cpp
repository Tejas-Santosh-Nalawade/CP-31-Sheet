#include<bits/stdc++.h>
using namespace std;

const int score[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long tt;
    cin>>tt;
    while(tt--)
    {
        char a[10][10];
        for(int i=0; i<10; i++) // N
        {
            string s;
            cin>>s;
            for(int j=0; j<10; j++) // N*N
            {
                a[i][j] = s[j];
            }
        }
        int total = 0;
        for(int i=0; i<10; i++) // N
        {
            for(int j=0; j<10; j++){  // N*N
                if(a[i][j] == 'X'){
                    total +=score[i][j];
                }
            }
        }
        cout<<total<<"\n";
    }

    return 0;
}

// TC : O(N*N + N*N) => O(N*N)
// SC : O(N*N)