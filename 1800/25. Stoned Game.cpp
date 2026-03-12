#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int tt;
	cin >> tt;

	
	while (tt--) {
	
		int numPiles;
		cin >> numPiles;
        
		vector<int> stones(numPiles);
		for (int &stoneCount : stones) {
            cin >> stoneCount;
		}
        
		int maxStonesInPile = *max_element(stones.begin(), stones.end());
		int totalStones = accumulate(stones.begin(), stones.end(), 0);
        
		if (maxStonesInPile * 2 > totalStones || (totalStones % 2 != 0)) {
            cout << "T" << endl;
		} else {
            cout << "HL" << endl;
		}
	}
    
	return 0;
}
