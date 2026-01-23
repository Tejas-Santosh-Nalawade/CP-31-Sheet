#include <bits/stdc++.h>
using namespace std;

int computeGCD(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int computeLCM(int a, int b) {
	return (a / computeGCD(a, b)) * b;
}

int computePower(int base, int exponent) {
	int result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			result *= base;
		}
		base *= base;
		exponent /= 2;
	}
	return result;
}

int main() {
	int testCases;
	cin >> testCases; 
	while (testCases--) {
		string inputString;
		cin >> inputString;
		int stringLength = inputString.size();
		int maxResult = 0; 

		for (int distance = 1; distance <= stringLength / 2; distance++) {
			int matchCount = 0;

			for (int i = 0; i < stringLength - distance; i++) {
				if (inputString[i] == inputString[i + distance] || inputString[i] == '?' || inputString[i + distance] == '?') {
					matchCount++;
				}

				if (i - distance >= 0) {
					if (inputString[i - distance] == inputString[i] || inputString[i - distance] == '?' || inputString[i] == '?') {
						matchCount--;
					}
				}

				if (i - distance >= -1 && matchCount == distance) {
					maxResult = 2 * distance;
				}
			}
		}
		cout << maxResult << endl; 
	}
	return 0;
}
