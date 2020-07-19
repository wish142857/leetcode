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


