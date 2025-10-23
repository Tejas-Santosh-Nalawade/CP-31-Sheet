
#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt; 

	while (tt--) {
		int n;
		cin >> n; 

		string s;
		cin >> s;

		string mex = ""; 

		for (char c = 'a'; c <= 'z'; c++) {
			if (s.find(c) == string::npos) { 
				mex = c;
				break;
			}
		}

		for (char c1 = 'a'; c1 <= 'z'; c1++) {
			for (char c2 = 'a'; c2 <= 'z'; c2++) {
				string tmp = "";
				tmp.push_back(c1);
				tmp.push_back(c2);

				if (mex == "" && s.find(tmp) == string::npos) {
					mex = tmp;
				}
			}
		}

		for (char c1 = 'a'; c1 <= 'z'; c1++) {
			for (char c2 = 'a'; c2 <= 'z'; c2++) {
				for (char c3 = 'a'; c3 <= 'z'; c3++) {
					string tmp = "";
					tmp.push_back(c1);
					tmp.push_back(c2);
					tmp.push_back(c3);

					if (mex == "" && s.find(tmp) == string::npos) {
						mex = tmp;
					}
				}
			}
		}

		cout << mex << "\n"; 
	}

	return 0;
}

