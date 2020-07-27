#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	vector<int> v{ 1,8,6,2,5,4,8,3,7 };
	vector<vector<int>> matrix{ { 9, 9, 4 }, { 6, 6, 8 }, { 2, 1, 1 } };
	auto solution = new s392::Solution();
	cout << solution->isSubsequence("abc", "ahbgdc") << endl;
	return 0;
}
