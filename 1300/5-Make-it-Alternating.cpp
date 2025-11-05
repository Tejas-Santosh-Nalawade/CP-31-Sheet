
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998'244'353;

void upd(int &a, int b) {
    a = (a * 1LL * b) % MOD;
}


int tt;
string s;

int main() {
	cin >> tt;
	for (int tc = 0; tc < tt; ++tc) {
	    cin >> s;
	    int res = 1;
	    int k = s.size();
	    int n = s.size();
	    for (int l = 0; l < n; ) {
	        int r = l + 1;
	        while(r < n && s[l] == s[r])
	            ++r;
            upd(res, r - l);
            --k;
            l = r;
	    }
	    
	    for (int i = 1; i <= k; ++i)
	        upd(res, i);
        cout << k << ' ' << res << endl;
	}
}