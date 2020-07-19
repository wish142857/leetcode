#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	vector<int> v{ 1, 3 };
	s528::Solution solution(v);
	
	
	cout << solution.pickIndex() << endl;
	cout << solution.pickIndex() << endl;
	cout << solution.pickIndex() << endl;
	cout << solution.pickIndex() << endl;
	return 0;
}
