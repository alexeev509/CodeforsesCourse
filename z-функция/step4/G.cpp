#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<int> ZFunction(vector<int> nums) {
	const size_t nums_size = nums.size();
	int left = 0, right = 0;
	std::vector<int> z_func(nums_size, 0);
	z_func[0] = nums_size;
	for (int i = 1; i < nums_size; ++i) {
		z_func[i] = max(0, min(right - i, z_func[i - left]));
		while (i + z_func[i] < nums_size && nums[z_func[i]] == nums[i + z_func[i]]) {
			++z_func[i];
		}
		if (i + z_func[i] > right) {
			left = i;
			right = i + z_func[i];
		}
	}
	return z_func;
}

int main() {
	size_t size, color;
	std::cin >> size >> color;
	std::vector<int> nums(2 * size + 1, -1);
	for (size_t i = 0; i < size; ++i) {
		std::cin >> nums[i];
		nums[2 * size - i] = nums[i];
	}
	auto z_func = ZFunction(nums);

	for (size_t i = size + 1; i < nums.size(); ++i) {
		if (z_func[i] == nums.size() - i && z_func[i] % 2 == 0) {
			std::cout << size - z_func[i] / 2 << ' ';
		}
	}
	std::cout << size;

	return 0;
}
