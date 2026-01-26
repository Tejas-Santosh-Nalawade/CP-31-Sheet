#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 300005; 
constexpr int MODULO = 998244353;

int arraySize; 
int numbers[MAX_N];
void addModulo(int &a, int b) {
	a += b;
	if (a >= MODULO)
		a -= MODULO;
}

int sumModulo(int a, int b) {
	a += b;
	if (a >= MODULO)
		a -= MODULO;
	if (a < 0)
		a += MODULO;
	return a;
}

int multiplyModulo(int a, int b) {
	return (a * 1LL * b) % MODULO;
}

int main() {
	std::cin >> arraySize; 
	for (int i = 0; i < arraySize; ++i)
		std::cin >> numbers[i]; 

	int result = 0; 
	for (int bitPosition = 0; bitPosition < 30; ++bitPosition) {
		int currentSum = 0; 
		std::vector<int> count(2, 0); 
		std::vector<int> leftSum(2, 0); 
		count[0] = 1; 
		int xoredValue = 0; 
		
		for (int i = 0; i < arraySize; ++i) {
			xoredValue ^= ((numbers[i] >> bitPosition) & 1);
			int rightSum = multiplyModulo(count[xoredValue ^ 1], i + 1);
			addModulo(currentSum, sumModulo(rightSum, -leftSum[xoredValue ^ 1]));
			++count[xoredValue];
			addModulo(leftSum[xoredValue], i + 1);
		}
		addModulo(result, multiplyModulo(1 << bitPosition, currentSum));
	}

	std::cout << result << std::endl;   
}
