#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	INT_MAX;
	vector<int> v{ 1,8,6,2,5,4,8,3,7 };
	vector<vector<int>> relation{ {0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4} };
	auto solution = new s264::Solution();
	cout << solution->nthUglyNumber(10) << endl;
	return 0;
}