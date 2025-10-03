#include <bits/stdc++.h>

using namespace std;

long long lcm(long long num1, long long num2) {
	return (num1 * num2) / (gcd(num1, num2));
}

long long calculateSum(long long start, long long end) {
	long long sum = ((start + end) * (end - start + 1)) / 2;
	return sum;
}

int main() {
	int tt; 
	cin >> tt;

	while (tt--) {
		long long n, x, y;
		cin >> n >> x >> y;

		long long count1 = (n / x) - (n / lcm(x, y)); 
		long long count2 = (n / y) - (n / lcm(x, y)); 

		long long ans = calculateSum(n - count1 + 1, n) - calculateSum(1LL, count2);
		cout << ans << endl;
	}
}

