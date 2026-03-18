#include <bits/stdc++.h>
using namespace std;

int main() {
	int element_count, target_count;
	std::cin >> element_count >> target_count;

	std::vector<int> input_elements(element_count);
	for (int& element : input_elements) {
		std::cin >> element;
	}

	std::queue<int> to_process;
	std::map<int, int> distance_map;

	for (const int& element : input_elements) {
		distance_map[element] = 0;
		to_process.push(element);
	}

	long long cumulative_distance = 0;
	std::vector<int> result;

	while (!to_process.empty() && result.size() < target_count) {
		int current = to_process.front();
		to_process.pop();

		if (distance_map[current] != 0) {
			cumulative_distance += distance_map[current];
			result.push_back(current);
		}

		if (!distance_map.count(current - 1)) {
			distance_map[current - 1] = distance_map[current] + 1;
			to_process.push(current - 1);
		}

		if (!distance_map.count(current + 1)) {
			distance_map[current + 1] = distance_map[current] + 1;
			to_process.push(current + 1);
		}
	}

	std::cout << cumulative_distance << std::endl;
	for (const auto& element : result) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	return 0;
}
