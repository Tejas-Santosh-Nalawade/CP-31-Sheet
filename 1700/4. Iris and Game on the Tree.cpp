#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

int power(int a, int b) {
	int result = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			result *= a;
		}
		a *= a;
		b /= 2;
	}
	return result;
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) {
		int nodeCount;
		cin >> nodeCount; 
		map<int, vector<int>> adjacencyList; 
		for (int i = 0; i < nodeCount - 1; ++i) {
			int node1, node2;
			cin >> node1 >> node2;
			adjacencyList[node1].push_back(node2);
			adjacencyList[node2].push_back(node1);
		}

		string nodeLabels;
		cin >> nodeLabels; 
		int questionMarksCount = 0; 
		for (char label : nodeLabels) {
			if (label == '?') {
				++questionMarksCount;
			}
		}

		int zeroCount = 0, oneCount = 0, questionCount = 0;
		for (const auto& entry : adjacencyList) {
			if (entry.first != 1 && entry.second.size() == 1) {
				if (nodeLabels[entry.first - 1] == '1') {
					++oneCount;
				} else if (nodeLabels[entry.first - 1] == '0') {
					++zeroCount;
				} else {
					++questionCount;
				}
			}
		}

		long long answer = 0;
		if (nodeLabels[0] != '?') {
			answer += nodeLabels[0] == '1' ? zeroCount + (questionCount + 1) / 2 : oneCount + (questionCount + 1) / 2;
		} else {
			answer = max(zeroCount, oneCount);
			if (zeroCount == oneCount && questionMarksCount % 2 == 1) {
				answer += (questionCount + 1) / 2;
			} else {
				answer += questionCount / 2;
			}
		}

		cout << answer << endl; 
	}
}