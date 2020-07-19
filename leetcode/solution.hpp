#pragma once
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

//---------------------------------------------
// @ID: #292
// @Date: 2020/7/19 
// @Algorithm: Number Theory Algorithm
// @Time: O(1)  
// @Space: O(1)
//---------------------------------------------
namespace s292 {
    class Solution {
    public:
        bool canWinNim(int n) {
            return n % 4;
        }
    };
}

//---------------------------------------------
// @ID: #312
// @Date: 2020/7/19 
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^3)  
// @Space: O(n^2)
//---------------------------------------------
namespace s312 {
    class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n + 2, vector<int>(n + 2));
            vector<int> v(n + 2);
            v[0] = v[n + 1] = 1;
            for (int i = 1; i <= n; i++)
                v[i] = nums[i - 1];
            for (int i = n - 1; i >= 0; i--)
                for (int j = i + 2; j <= n + 1; j++)
                    for (int k = i + 1; k < j; k++) {
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
                    }
            return dp[0][n + 1];
        }
    };
}

//---------------------------------------------
// @ID: #319
// @Date: 2020/7/19
// @Algorithm: Number Theory Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s319 {
    class Solution {
    public:
        int bulbSwitch(int n) {
            return sqrt(n);
        }
    };
}

//---------------------------------------------
// @ID: #375
// @Date: 2020/7/19 
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^3)  
// @Space: O(n^2)
//---------------------------------------------
namespace s375 {
    class Solution {
    public:
        int getMoneyAmount(int n) {
            vector<vector<int>> dp(n + 1, vector<int>(n + 1));
            for (int i = n; i >= 1; i--) {
                for (int j = i + 1; j <= n; j++) {
                    dp[i][j] = min(dp[i + 1][j] + i, dp[i][j - 1] + j);
                    for (int k = i + 1; k < j; k++) {
                        dp[i][j] = min(dp[i][j], max(dp[i][k - 1] + k, dp[k + 1][j] + k));
                    }
                }
            }
            return dp[1][n];
        }
    };
}

//---------------------------------------------
// @ID: #382
// @Date: 2020/7/19 
// @Algorithm: Reservoir Sampling Algorithm
// @Time: O(n)  
// @Space: O(1)
//---------------------------------------------
namespace s382 {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        /** @param head The linked list's head.
            Note that the head is guaranteed to be not null, so it contains at least one node. */
        Solution(ListNode* head) {
            this->head = head;
            srand((unsigned)time(NULL));
            return;
        }

        /** Returns a random node's value. */
        int getRandom() {
            ListNode* p = head;
            int i = 1, v = p->val, d = 0;
            p = p->next;
            while (p != NULL) {
                d = rand() % (i + 1);
                if (d == 0)
                    v = p->val;
                i++;
                p = p->next;
            }
            return v;
        }
    private:
        ListNode* head;
    };
}

//---------------------------------------------
// @ID: #398
// @Date: 2020/7/19 
// @Algorithm: Reservoir Sampling Algorithm
// @Time: O(n)  
// @Space: O(1)
//---------------------------------------------
namespace s398 {
    class Solution {
    public:
        vector<int>& nums;
        Solution(vector<int>& nums) : nums(nums) {
            srand((unsigned)time(NULL));
            return;
        }

        int pick(int target) {
            int count = 0, ans = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == target) {
                    count++;
                    if (rand() % count == 0)
                        ans = i;
                }
            }
            return ans;
        }
    };

    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(nums);
     * int param_1 = obj->pick(target);
     */
}

//---------------------------------------------
// @ID: #470
// @Date: 2020/7/19 
// @Algorithm: Rejection Sampling Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s470 {
    // The rand7() API is already defined for you.
    // int rand7();
    // @return a random integer in the range 1 to 7
    class Solution {
    public:
        Solution() {
            srand((int)time(NULL));
        }

        int rand7() {
            return (rand() % 7) + 1;
        }

        int rand10() {
            int x = 0;
            do {
                x = (rand7() - 1) * 7 + rand7();
            } while (x > 40);
            return (x % 10) + 1;
        }
    };
}

//---------------------------------------------
// @ID: #478
// @Date: 2020/7/19 
// @Algorithm: Rejection Sampling Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s478 {
    class Solution {
    public:
        std::mt19937 rng{ std::random_device{}() };
        std::uniform_real_distribution<double> uni{ 0, 1 };

        double r, x, y;
        Solution(double radius, double x_center, double y_center) {
            r = radius;
            x = x_center;
            y = y_center;
        }

        vector<double> randPoint() {
            double rx, ry;
            do {
                rx = uni(rng) * 2 - 1;
                ry = uni(rng) * 2 - 1;
            } while (pow(rx, 2) + pow(ry, 2) > 1);
            return vector<double>{ x + rx * r, y + ry * r };

        }
    };

    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(radius, x_center, y_center);
     * vector<double> param_1 = obj->randPoint();
     */
}

//---------------------------------------------
// @ID: #486
// @Date: 2020/7/19 
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(n^2)
//---------------------------------------------
namespace s486 {
    class Solution {
    public:
        bool PredictTheWinner(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n, vector<int>(n));
            for (int i = n - 1; i >= 0; i--) {
                dp[i][i] = nums[i];
                for (int j = i + 1; j <= n - 1; j++)
                    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
            return dp[0][n - 1] >= 0;
        }
    };
}


//---------------------------------------------
// @ID: #777
// @Date: 2020/7/19 
// @Algorithm: Simple Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s777 {
    class Solution {
    public:
        bool canTransform(string start, string end) {
            if (start.length() != end.length())
                return false;
            int i = 0, j = 0;
            while (true) {
                while (i < start.length() && start[i] == 'X')
                    i++;
                while (j < end.length() && end[j] == 'X')
                    j++;
                if (i < start.length() && j < end.length()) {
                    if (start[i] != end[j])
                        return false;
                    if (start[i] == 'L' && i < j)
                        return false;
                    if (start[i] == 'R' && i > j)
                        return false;
                    i++, j++;
                }
                else
                    break;
            }
            while (i < start.length()) {
                if (start[i] != 'X')
                    return false;
                i++;
            }
            while (j < end.length()) {
                if (end[j] != 'X')
                    return false;
                j++;
            }
            return true;
        }
    };
}


//---------------------------------------------
// @ID: #843
// @Date: 2020/7/19 
// @Algorithm: Minimax Algorithm
// @Time: O(n^2)
// @Space: O(1)
//---------------------------------------------
namespace s843 {
    /**
    * // This is the Master's API interface.
    * // You should not implement it, or speculate about its implementation
    * class Master {
    *   public:
    *     int guess(string word);
    * };
    */
    class Master {
        public:
            string secret;
            Master(string secret) : secret(secret) { }
            int guess(string word) {
                int s = 0;
                for (int k = 0; k < 6; k++)
                    if (secret[k] == word[k])
                        s++;
                cout << "Call guess: " << word << endl;
                return s;
            }
    };
    class Solution {
    public:
        void findSecretWord(vector<string>& wordlist, Master& master) {
            int counter[7] = { 0 };
            int i = 0, j = 0, k = 0, s = 0, ret = 0, max = 0, min = 0;
            string word;
            for (int t = 0; t < 10; t++) {
                min = INT_MAX;
                for (i = 0; i < wordlist.size(); i++) {
                    memset(counter, 0, sizeof(counter));
                    for (j = 0; j < wordlist.size(); j++) {
                        s = 0;
                        for (k = 0; k < 6; k++)
                            if (wordlist[i][k] == wordlist[j][k])
                                s++;
                        counter[s]++;
                    }
                    max = 1;
                    for (k = 0; k < 6; k++)
                        if (counter[k] > max)
                            max = counter[k];
                    if (max < min) {
                        min = max;
                        word = wordlist[i];
                    }
                }
                ret = master.guess(word);
                if (ret == 6)
                    break;
                vector<string>::iterator it = wordlist.begin();
                while (it != wordlist.end()) {
                    s = 0;
                    for (k = 0; k < 6; k++)
                        if ((*it)[k] == word[k])
                            s++;
                    if (s != ret)
                        it = wordlist.erase(it);
                    else
                        it++;
                }
            }
            return;
        }
    };
}


//---------------------------------------------
// @ID: #877
// @Date: 2020/7/19
// @Algorithm: Simple Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s877 {
    class Solution {
    public:
        bool stoneGame(vector<int>& piles) {
            return true;
        }
    };
}


//---------------------------------------------
// @ID: #1033
// @Date: 2020/7/19
// @Algorithm: Simple Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s1033 {
    class Solution {
    public:
        vector<int> numMovesStones(int a, int b, int c) {
            int x, y, z;
            if (b > c) {
                if (a > b)
                    x = c, y = b, z = a;
                else if (a < c)
                    x = a, y = c, z = b;
                else
                    x = c, y = a, z = b;
            }
            else {
                if (a > c)
                    x = b, y = c, z = a;
                else if (a < b)
                    x = a, y = b, z = c;
                else
                    x = b, y = a, z = c;
            }
            int maximum_moves = z - x - 2;
            int minimum_moves = (z - y > 2 && y - x > 2) ? 2 : ((z - y == 1 && y - x == 1) ? 0 : 1);
            return { minimum_moves, maximum_moves };
        }
    };

}

//---------------------------------------------
// @ID: #1227
// @Date: 2020/7/19
// @Algorithm: Number Theory Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s1227 {
    class Solution {
    public:
        double nthPersonGetsNthSeat(int n) {
            return n > 1 ? 0.5 : 1.0;
        }
    };
}

//---------------------------------------------
// @ID: #1503
// @Date: 2020/7/19
// @Algorithm: Simple Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s1503 {
    class Solution {
    public:
        int getLastMoment(int n, vector<int>& left, vector<int>& right) {
            int m = 0;
            for (auto i : left)
                m = max(m, i);
            for (auto i : right)
                m = max(m, n - i);
            return m;
        }
    };
}


//---------------------------------------------
// @ID: #1512
// @Date: 2020/7/19
// @Algorithm: Simple Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s1512 {
    class Solution {
    public:
        int numIdenticalPairs(vector<int>& nums) {
            int counter[101] = { 0 }, ans = 0;
            for (auto i : nums)
                counter[i]++;
            for (int i = 1; i <= 100; i++)
                ans += (counter[i] > 1 ? ((counter[i] * (counter[i] - 1)) >> 1) : 0);
            return ans;
        }
    };
}
