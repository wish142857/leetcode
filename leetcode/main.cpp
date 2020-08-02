#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	INT_MAX;
	vector<int> v{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100 };
	vector<vector<int>> relation{ {0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4} };
	auto solution = new s416::Solution();
	cout << solution->canPartition(v) << endl;
	return 0;
}