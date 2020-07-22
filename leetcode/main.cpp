#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	vector<int> v{ 2,3,1,1,4 };
	s45::Solution solution;
	cout << solution.jump(v) << endl;
	return 0;
}
