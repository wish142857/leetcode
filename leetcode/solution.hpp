#pragma once
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using std::vector;


namespace s292 {
    //---------------------------------------------
    // @Date: 2020/7/19 
    // @Algorithm: Number Theory Algorithm
    // @Time: O(1)  
    // @Space: O(1)
//---------------------------------------------
    class Solution {
    public:
        bool canWinNim(int n) {
            return n % 4;
        }
    };
}

namespace s382 {
    //---------------------------------------------
    // @Date: 2020/7/19 
    // @Algorithm: Reservoir Sampling Algorithm
    // @Time: O(n)  
    // @Space: O(1)
    //---------------------------------------------
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

namespace s398 {
    //---------------------------------------------
    // @Date: 2020/7/19 
    // @Algorithm: Reservoir Sampling Algorithm
    // @Time: O(n)  
    // @Space: O(1)
    //---------------------------------------------
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


namespace s470 {
    //---------------------------------------------
    // @Date: 2020/7/19 
    // @Algorithm: Rejection Sampling Algorithm
    // @Time: O(1)
    // @Space: O(1)
    //---------------------------------------------
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

namespace s478 {
    //---------------------------------------------
    // @Date: 2020/7/19 
    // @Algorithm: Rejection Sampling Algorithm
    // @Time: O(1)
    // @Space: O(1)
    //---------------------------------------------
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
