#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	s478::Solution solution(100.0, 200.0 , 200.0);


	cout << solution.randPoint()[0] << solution.randPoint()[1] << endl;
	return 0;
}
