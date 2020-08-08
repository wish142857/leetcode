#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	INT_MAX;
	vector<string> input{ "XOX","O O","XOX" };
	auto solution = new s794::Solution();
	cout << solution->validTicTacToe(input) << endl;
	return 0;
}