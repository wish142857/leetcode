#include "solution.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>


namespace s977 {
	class Solution {
	public:
		vector<int> sortedSquares(vector<int>& nums) {
			int n = nums.size(), i = 0, j = n - 1, k = n - 1;
			vector<int> ans(n, 0);
			while (i < j) {
				int a = nums[i] * nums[i];
				int b = nums[j] * nums[j];
				if (a > b) {
					ans[k--] = a;
					i++;
				}
				else {
					ans[k--] = b;
					j--;
				}
			}
			ans[k--] = nums[i] * nums[i];
			return ans;
		}
	};
}



int main() {
	std::cout << "Main::Compiled successfully" << std::endl;
	return 0;
}
