#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	vector<vector<int>> matrix{ { 9, 9, 4 }, { 6, 6, 8 }, { 2, 1, 1 } };
	auto solution = new s329::Solution();
	cout << solution->longestIncreasingPath(matrix) << endl;
	return 0;
}
