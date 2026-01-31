#include<bits/stdc++.h>

using namespace std;

int commonPrefixLength(const vector<int>& vec1, const vector<int>& vec2) {
	int commonLength = 0;
	while (commonLength < static_cast<int>(vec1.size()) && vec1[commonLength] == vec2[commonLength]) {
		++commonLength;
	}
	return commonLength;
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); 

	int testCases;
	cin >> testCases; 

	while (testCases--) {
		int rows, cols;
		cin >> rows >> cols; 
		vector<vector<int>> original(rows, vector<int>(cols));
		vector<vector<int>> transformed(rows, vector<int>(cols));

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j) {
				cin >> original[i][j];
				--original[i][j];
			}

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j) {
				transformed[i][original[i][j]] = j;
			}

		sort(transformed.begin(), transformed.end());

		for (int i = 0; i < rows; ++i) {
			int position = lower_bound(transformed.begin(), transformed.end(), original[i]) - transformed.begin();
			int maxCommonPrefix = 0;

			if (position > 0) {
				maxCommonPrefix = max(maxCommonPrefix, commonPrefixLength(original[i], transformed[position - 1]));
			}
			if (position < rows) {
				maxCommonPrefix = max(maxCommonPrefix, commonPrefixLength(original[i], transformed[position]));
			}

			cout << maxCommonPrefix << " ";
		}

		cout << '\n'; 
	}

	return 0;
}
