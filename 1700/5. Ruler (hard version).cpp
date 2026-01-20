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
	int testCaseCount;
	cin >> testCaseCount;

	while (testCaseCount--) {
		int left = 1;
		int right = 1000;
		int answer = 0;

		while (left <= right) {
			int mid1 = left + (right - left) / 3;
			int mid2 = right - (right - left) / 3;

			if (mid1 > mid2) break;

			int productComparison = mid1 * mid2;
			int increaseBoth = (mid1 + 1) * (mid2 + 1);
			int increaseMid2 = mid1 * (mid2 + 1);

			cout << "? " << mid1 << " " << mid2 << endl;
			cout.flush();

			int number;
			cin >> number;

			if (number == productComparison) {
				left = mid2 + 1;
			} else if (number == increaseBoth) {
				right = mid1 - 1;
				answer = mid1;
			} else if (number == increaseMid2) {
				left = mid1 + 1;
				answer = mid2;
				right = mid2 - 1;
			} else {
				break;
			}
		}
		cout << "! " << answer << endl;
	}
}