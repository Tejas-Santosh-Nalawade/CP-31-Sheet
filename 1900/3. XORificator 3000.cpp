#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
	while (b != 0) {
		ll temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}

ll power(ll a, ll b) {
	ll result = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			result *= a;
		}
		a *= a;
		b /= 2;
	}
	return result;
}

ll xorUpTo(ll n) {
	if (n % 4 == 0) return n;
	if (n % 4 == 1) return 1;
	if (n % 4 == 2) return n + 1;
	return 0;
}

ll calculateXorWithMask(ll n, ll bitIndex, ll mask) {
	if (n <= 0) return 0;

	ll result = xorUpTo(n);
	ll reducedNumber = n >> bitIndex;

	if (n % (1LL << bitIndex) < mask) {
		reducedNumber--;
	}

	ll maskedXor = xorUpTo(reducedNumber) << bitIndex;
	if (reducedNumber % 2 == 0) {
		maskedXor ^= mask;
	}

	result ^= maskedXor;
	return result;
}

int main() {
	ll testCases;
	cin >> testCases;
	while (testCases--) {
		ll left, right, bitIndex, mask;
		cin >> left >> right >> bitIndex >> mask;

		ll result = calculateXorWithMask(right, bitIndex, mask) ^ calculateXorWithMask(left - 1, bitIndex, mask);
		cout << result << endl;
	}
}

