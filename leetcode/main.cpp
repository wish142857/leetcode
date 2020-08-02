#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	INT_MAX;
	vector<int> v{ 3, 33, 333 };
	vector<vector<int>> relation{ {0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4} };
	auto solution = new s377::Solution();
	cout << solution->combinationSum4(v, 10000) << endl;
	return 0;
}