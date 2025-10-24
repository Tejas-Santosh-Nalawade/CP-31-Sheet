#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool is_palindrome=1;
	int cnt_0 = 0;
	for(int i=0;i<n;i++){
		cnt_0 += s[i]=='0';
	}
	if(cnt_0 == 1){
		cout << "BOB\n";
		return;
	}
	if(cnt_0%2){
		cout << "ALICE\n";
		return;
	}
	cout << "BOB\n";
	return;
}

signed main()
{
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
    return 0;
}