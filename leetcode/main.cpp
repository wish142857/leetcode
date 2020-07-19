#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	s843::Solution solution;
	s843::Master master("ccbazz");
	vector<string> wordlist{ "acckzz","ccbazz","eiowzz","abcczz" };
	vector<int> v{ 0 };
	solution.findSecretWord(wordlist, master);
	return 0;
}
