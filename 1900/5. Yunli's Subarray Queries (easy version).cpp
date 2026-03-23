#include <bits/stdc++.h>
using namespace std;


using Long = long long;
using LongPair = pair<Long, Long>;

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

Long power(Long a, Long b) {
	Long result = 1;
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
	Long testCases;
	cin >> testCases;

	while (testCases--) {
		Long n, k, q;
		cin >> n >> k >> q;
		vector<Long> array(n);

		for (Long& value : array) {
			cin >> value;
		}

		for (Long i = 0; i < n; ++i) {
			array[i] -= i;
		}

		vector<LongPair> results;
		map<Long, Long> frequencyMap;
		LongPair maxFrequency = {0, 0};

		for (Long i = 0; i < k; ++i) {
			frequencyMap[array[i]]++;
		}

		for (const auto& entry : frequencyMap) {
			if (entry.second > maxFrequency.first) {
				maxFrequency = {entry.second, entry.first};
			}
		}

		results.emplace_back(k - maxFrequency.first, maxFrequency.second);

		for (Long i = k; i < n; ++i) {
			frequencyMap[array[i - k]]--;
			if (frequencyMap[array[i - k]] == 0) {
				frequencyMap.erase(array[i - k]);
			}
			frequencyMap[array[i]]++;
			if (maxFrequency.second == array[i - k]) {
				maxFrequency = {0, 0};
				for (const auto& entry : frequencyMap) {
					if (entry.second > maxFrequency.first) {
						maxFrequency = {entry.second, entry.first};
					}
				}
			} else if (maxFrequency.first < frequencyMap[array[i]]) {
				maxFrequency = {frequencyMap[array[i]], array[i]};
			}

			results.emplace_back(k - maxFrequency.first, maxFrequency.second);
		}

		for (Long i = 0; i < q; ++i) {
			Long left, right;
			cin >> left >> right;
			cout << results[left - 1].first << endl;
		}
	}
}