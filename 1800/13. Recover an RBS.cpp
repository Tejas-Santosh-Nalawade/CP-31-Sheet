#include<bits/stdc++.h>
using namespace std;
#define int long long

auto check = [] (const string &s){
    int bal = 0;
    for(char c: s){
        if(c == '(') ++bal;
        if(c == ')') --bal;
        if(bal < 0 ) return false; 
    }
    return bal == 0;
};

void solve(){
    string s;
    cin>>s;

    vector<int>pos;
    int open = s.length()/ 2, close = s.length() / 2;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '?') pos.push_back(i);
        if(s[i] == '(') --open;
        if(s[i] == ')')  --close;
    }
    for (int i=0; i<pos.size(); i++){
        if(i < open) s[pos[i]] = '(';
        else s[pos[i]] = ')';
    }
    bool ok = true;
    if(open > 0 && close > 0){
        swap(s[pos[open - 1]], s[pos[open]]);

        if(check(s)) ok = false;
    }
    cout<<(ok ? "YES\n": "NO\n");

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin >> tt;
    while (tt--) solve();
}
