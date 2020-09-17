#include "solution.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

int coinChange(vector<int>& coins, int amount) {
	int minNum = INT_MAX, m = coins.size();
	vector<int> dp(amount + 1, 0);
	for (int i = 1; i <= amount; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; j < m; j++) {
			if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[amount] != INT_MAX ? dp[amount] : -1;
}


int main() {
	int i = 0;
	string str = "123";
	sscanf_s(str.c_str(), "%d", &i);
	int j = 12345;
	string str2;
	int a[100];
	memset(a, 0, sizeof(a));


	cout << i << endl;
	vector<int> v;
	queue<int> q;
	stack<int> s;
	unordered_set<int> us;
	priority_queue<int> pq;

	v.insert(v.begin(), 1);
	v.insert(v.begin(), 2);
	v.insert(v.begin(), 3);
	v.insert(v.begin(), 4);
	/*
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "  ";
	cout << endl;
	*/

	v.erase(v.begin() + 2);
	/*
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "  ";
	cout << endl;
	*/

	v.push_back(1);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	/*
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << endl << endl;
	*/
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	/*
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	*/




	return 0;
}