#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;

	while (tt--) {
		int arraySize, queries;
		cin >> arraySize >> queries;
		vector<ll> array(arraySize + 1);
		for (int i = 1; i <= arraySize; i++) {
			cin >> array[i]; 
		}

		vector<ll> prefixSum(arraySize + 1, 0), prefixXor(arraySize + 1, 0);
		for (int i = 1; i <= arraySize; i++) {
			prefixSum[i] = prefixSum[i - 1] + array[i]; 
			prefixXor[i] = prefixXor[i - 1] ^ array[i]; 
		}

		int L = 1, R = arraySize;
		int queryL, queryR;
		cin >> queryL >> queryR; 

		ll maxFunctionValue = -1; 
		int minSegmentLength = arraySize + 1; 
		int resultL = L, resultR = L; 

		for (int l = L; l <= R; l++) {
			ll sumLR = prefixSum[R] - prefixSum[l - 1];
			ll xorLR = prefixXor[R] ^ prefixXor[l - 1];
			ll functionLR = sumLR - xorLR;

			if (functionLR < maxFunctionValue) continue;

			int low = l, high = R;
			while (low < high) {
				int mid = (low + high) / 2;
				ll sumLM = prefixSum[mid] - prefixSum[l - 1];
				ll xorLM = prefixXor[mid] ^ prefixXor[l - 1];
				ll functionLM = sumLM - xorLM;

				if (functionLM < functionLR) {
					low = mid + 1;
				} else {
					high = mid;
				}
			}

			int r = low;
			int segmentLength = r - l + 1; 

			if (functionLR > maxFunctionValue || (functionLR == maxFunctionValue && segmentLength < minSegmentLength)) {
				maxFunctionValue = functionLR;
				minSegmentLength = segmentLength;
				resultL = l;
				resultR = r;
			}
		}

		cout << resultL << " " << resultR << "\n";
	}

	return 0;
}