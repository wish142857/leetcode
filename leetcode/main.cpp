#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	INT_MAX;
	vector<vector<int>> relation{ {-84, -36, 2},{87, -79, 10},{42, 10, 63} };
	auto solution = new s931::Solution();
	cout << solution->minFallingPathSum(relation) << endl;
	return 0;
}