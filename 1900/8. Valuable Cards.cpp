#include<bits/stdc++.h>

using namespace std;

using Long = long long;

Long gcd(Long a, Long b) {
	while (b != 0) {
		Long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

Long lcm(Long a, Long b) {
	return (a / gcd(a, b)) * b;
}

Long power(Long base, Long exponent) {
	Long result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			result *= base;
		}
		base *= base;
		exponent /= 2;
	}
	return result;
}

vector<Long> findFactors(Long x) {
	vector<Long> factors;
	for (Long i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			factors.push_back(i);
			if (i != x / i) {
				factors.push_back(x / i);
			}
		}
	}
	sort(factors.begin(), factors.end());
	return factors;
}

int main() {
	Long testCases;
	cin >> testCases;

	while (testCases--) {
		Long n, x;
		cin >> n >> x;

		vector<Long> array(n);
		for (Long i = 0; i < n; i++) {
			cin >> array[i];
		}

		vector<Long> factors = findFactors(x);
		Long result = 1;
		Long numFactors = factors.size();
		vector<bool> isProductPossible(numFactors, false);
		isProductPossible[0] = true;

		for (Long num : array) {
			if (x % num != 0) {
				continue;
			}
			for (Long j = numFactors - 1; j >= 0; j--) {
				if (isProductPossible[j]) {
					Long product = num * factors[j];
					if (x % product == 0) {
						Long index = lower_bound(factors.begin(), factors.end(), product) - factors.begin();
						isProductPossible[index] = true;
					}
				}
			}
			if (isProductPossible[numFactors - 1]) {
				isProductPossible.assign(numFactors, false);
				isProductPossible[0] = true;
				Long index = lower_bound(factors.begin(), factors.end(), num) - factors.begin();
				isProductPossible[index] = true;
				result++;
			}
		}
		cout << result << endl;
	}
}