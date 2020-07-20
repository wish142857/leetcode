#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	vector<int> v{ 2, 7, 11, 15 };
	s167::Solution solution;
	cout << solution.twoSum(v, 9)[0] << endl;
	cout << solution.twoSum(v, 9)[1] << endl;
	return 0;
}
