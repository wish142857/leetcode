﻿#pragma once
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;


//---------------------------------------------
// @ID: #1
// @Date: 2020/7/21
// @Algorithm: Hash Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s1 {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            multiset<int> numSet;
            for (int i = 0; i < int(nums.size()); i++) {
                int n = target - nums[i];
                if (numSet.count(n) > 0) {
                    int j = 0;
                    for (; j < i; j++)
                        if (nums[j] == n)
                            break;
                    return { j, i };
                }
                numSet.insert(nums[i]);
            }
            return { };
        }
    };
}


//---------------------------------------------
// @ID: #2
// @Date: 2020/7/21
// @Algorithm: List Algorithm | Linked List
// @Time: O(max(m, n))
// @Space: O(max(m, n))
//---------------------------------------------
namespace s2 {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* p = l1, * q = l2, * r = NULL, * t = NULL;
            int n = 0;
            r = new ListNode(p->val + q->val);
            t = r;
            p = p->next;
            q = q->next;
            while (p != NULL && q != NULL) {
                t->next = new ListNode(p->val + q->val);
                t = t->next;
                p = p->next;
                q = q->next;
            }
            while (p != NULL) {
                t->next = new ListNode(p->val);
                t = t->next;
                p = p->next;
            }
            while (q != NULL) {
                t->next = new ListNode(q->val);
                t = t->next;
                q = q->next;
            }
            t = r;
            while (true) {
                t->val = t->val + n;
                n = t->val / 10;
                t->val = t->val % 10;
                if (t->next == NULL) {
                    if (n > 0)
                        t->next = new ListNode(n);
                    break;
                }
                t = t->next;
            }
            return r;
        }
    };
}


// TODO
namespace s5 {
    class Solution {
    public:
        string longestPalindrome(string s) {
            int ans = 0;
            vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
            for (int i = s.size() - 1; i >= 0; i--) {
                dp[i][i] = true;
                for (int j = i + 1; j < int(s.size()); j++) {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                    ans = max(ans, j - i + 1);
                }
            }
            
        }
    };
}


//---------------------------------------------
// @ID: #7
// @Date: 2020/7/26
// @Algorithm: Simple Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s7 {
    class Solution {
    public:
        int reverse(int x) {
            long y = 0;
            while (x) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            return y <= INT_MAX && y >= INT_MIN ? y : 0;
        }
    };
}


//---------------------------------------------
// @ID: #11
// @Date: 2020/7/26
// @Algorithm: Greedy Algorithm | Two Points Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s11 {
    class Solution {
    public:
        int maxArea(vector<int>& height) {
            int i = 0, j = height.size() - 1;
            int ans = 0;
            while (i < j) {
                ans = max(ans, min(height[i], height[j]) * (j - i));
                if (height[i] < height[j])
                    i++;
                else if (height[i] > height[j])
                    j--;
                else
                    i++, j--;
            }
            return ans;
        }
    };
}


//---------------------------------------------
// @ID: #19
// @Date: 2020/7/21
// @Algorithm: List Algorithm | Linked List, Two Points
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s19 {
     struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* h = new ListNode(0);
            h->next = head;
            ListNode *slow = h, *fast = h;
            for (int i = 0; i <= n; i++)
                fast = fast->next;
            while (fast)
                fast = fast->next, slow = slow->next;
            if (slow && slow->next)
                slow->next = slow->next->next;
            return h->next;
        }
    };
}


//---------------------------------------------
// @ID: #21
// @Date: 2020/7/21
// @Algorithm: List Algorithm | Linked List
// @Time: O(n + m)
// @Space: O(1)
//---------------------------------------------
namespace s21 {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *h, *p;
            if (l1 && l2) {
                if (l1->val <= l2->val)
                    h = l1, l1 = l1->next;
                else
                    h = l2, l2 = l2->next;
            }
            else if (l1)
                h = l1, l1 = l1->next;
            else if (l2)
                h = l2, l2 = l2->next;
            else
                return nullptr;
            p = h;
            while (l1 && l2) {
                if (l1->val <= l2->val)
                    p->next = l1, p = p->next, l1 = l1->next;
                else
                    p->next = l2, p = p->next, l2 = l2->next;
            }
            if (l1)
                p->next = l1;
            else if (l2)
                p->next = l2;
            return h;
        }
    };
}


//---------------------------------------------
// @ID: #45
// @Date: 2020/7/21
// @Algorithm: Greedy Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s45 {
    class Solution {
    public:
        int jump(vector<int>& nums) {
            int i = 0, j = 0, k = 0, times = 0;
            while (true) {
                if (k >= int(nums.size()) - 1)
                    return times;
                times++;
                while (i <= j)
                    k = max(k, i + nums[i]), i++;
                j = k;
            }
            return 0;
        }
    };
}


//---------------------------------------------
// @ID: #55
// @Date: 2020/7/21
// @Algorithm: Greedy Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s55 {
    class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int i = 0, j = 0;
            while (i <= j) {
                j = max(j, i + nums[i]);
                if (j >= int(nums.size()) - 1)
                    return true;
                i++;
            }
            return false;
        }
    };
}


//---------------------------------------------
// @ID: #64
// @Date: 2020/7/23
// @Algorithm: Dynamic Algorithm
// @Time: O(n*m)
// @Space: O(n*m)
//---------------------------------------------
namespace s64 {
    class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            if (grid.size() == 0 || grid[0].size() == 0)
                return 0;
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n));
            dp[0][0] = grid[0][0];
            for (int j = 1; j < n; j++)
                dp[0][j] = dp[0][j - 1] + grid[0][j];
            for (int i = 1; i < m; i++) {
                dp[i][0] = dp[i - 1][0] + grid[i][0];
                for (int j = 1; j < n; j++)
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
            return dp[m - 1][n - 1];
        }
    };
}


//---------------------------------------------
// @ID: #75
// @Date: 2020/7/26
// @Algorithm: Two Points Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s75 {
    class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int i = 0, j = nums.size() - 1, k = 0;
            while (k <= j) {
                if (nums[k] == 0) {
                    nums[k++] = nums[i];
                    nums[i++] = 0;
                }
                else if (nums[k] == 2) {
                    nums[k] = nums[j];
                    nums[j--] = 2;
                }
                else {
                    k++;
                }
            }
            return;
        }
    };
}


//---------------------------------------------
// @ID: #95
// @Date: 2020/7/21
// @Algorithm: Tree Algorithm
// @Time: O(?)
// @Space: O(?)
//---------------------------------------------
namespace s95 {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        vector<TreeNode*> generateTrees(int l, int r) {
            if (l > r)
                return { nullptr };
            vector<TreeNode*> ans;
            for (int k = l; k <= r; k++) {
                vector<TreeNode*> left = generateTrees(l, k - 1);
                vector<TreeNode*> right = generateTrees(k + 1, r);
                for (unsigned int i = 0; i < left.size(); i++)
                    for (unsigned int j = 0; j < right.size(); j++) {
                        TreeNode* tree = new TreeNode(k, left[i], right[j]);
                        ans.push_back(tree);
                    }
            }
            return ans;
        }

        vector<TreeNode*> generateTrees(int n) {
            if (n > 0)
                return generateTrees(1, n);
            return {};
        }
    };
}


//---------------------------------------------
// @ID: #122
// @Date: 2020/7/21
// @Algorithm: Greedy Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s122 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            for (int i = 1; i < int(prices.size()); i++) {
                if (prices[i] > prices[i - 1])
                    profit += (prices[i] - prices[i - 1]);
            }
            return profit;
        }
    };
}


//---------------------------------------------
// @ID: #125
// @Date: 2020/7/26
// @Algorithm: Two Points Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s125 {
    class Solution {
    public:
        bool isPalindrome(string s) {
            string _s;
            for (char c : s)
                if (isalnum(c))
                    _s += tolower(c);
            int left = 0, right = _s.size() - 1;
            while (left < right)
                if (_s[left++] != _s[right--])
                    return false;
            return true;
        }
    };
}


//---------------------------------------------
// @ID: #141
// @Date: 2020/7/27
// @Algorithm: Two Points Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s141 {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        bool hasCycle(ListNode* head) {
            ListNode *slow = head, *fast = head;
            while (fast) {
                fast = fast->next;
                if (fast == slow)
                    return true;
                if (!fast)
                    return false;
                fast = fast->next;
                slow = slow->next;
            }
            return false;
        }
    };
}


//---------------------------------------------
// @ID: #153
// @Date: 2020/7/22
// @Algorithm: Binary Search Algorithm
// @Time: O(log n)
// @Space: O(1)
//---------------------------------------------
namespace s153 {
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            int left = 0, right = nums.size() - 1, mid = 0;
            while (left != right) {
                mid = left + ((right - left) >> 1);
                if (nums[mid] < nums[right])
                    right = mid;
                else
                    left = mid + 1;
            }
            return nums[left];
        }
    };
}


//---------------------------------------------
// @ID: #154
// @Date: 2020/7/22
// @Algorithm: Binary Search Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s154 {
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            int i = 0, j = nums.size() - 1, mid = 0;
            while (i != j) {
                mid = i + ((j - i) >> 1);
                if (nums[mid] < nums[j]) {
                    j = mid;
                }
                else if (nums[mid] > nums[j]) {
                    i = mid + 1;;
                }
                else {
                    j--;
                }
            }
            return nums[i];
        }
    };
}


//---------------------------------------------
// @ID: #167
// @Date: 2020/7/20 
// @Algorithm: Two Pointers Algorithm
// @Time: O(n)  
// @Space: O(1)
//---------------------------------------------
namespace s167 {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int l = 0, r = numbers.size() - 1, sum = 0;
            while (l != r) {
                sum = numbers[l] + numbers[r];
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else
                    return { l + 1, r + 1 };
            }
            return { 0, 0 };
        }
    };
}


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
            return int(sqrt(n));
        }
    };
}


//---------------------------------------------
// @ID: #329
// @Date: 2020/7/26
// @Algorithm: Dynamic Algorithm
// @Time: O(m * n)
// @Space: O(m * n)
//---------------------------------------------
namespace s329 {
    class Solution {
    public:
        int m = 0, n = 0;

        int longestIncreasingPath(vector<vector<int>>& matrix) {
            if (matrix.size() == 0 or matrix[0].size() == 0)
                return 0;
            m = matrix.size(), n = matrix[0].size();
            vector<vector<int>> dp(m, vector<int>(n));
            int ans = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    ans = max(ans, calculate(matrix, dp, i, j));
            return ans;
        }
    private:
        int calculate(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y) {
            if (dp[x][y] > 0)
                return dp[x][y];
            int ans = 1;
            if (x > 0 && matrix[x][y] > matrix[x - 1][y])
                ans = max(ans, (dp[x - 1][y] > 0 ? dp[x - 1][y] : calculate(matrix, dp, x - 1, y)) + 1);
            if (x < m - 1 && matrix[x][y] > matrix[x + 1][y])
                ans = max(ans, (dp[x + 1][y] > 0 ? dp[x + 1][y] : calculate(matrix, dp, x + 1, y)) + 1);
            if (y > 0 && matrix[x][y] > matrix[x][y - 1])
                ans = max(ans, (dp[x][y - 1] > 0 ? dp[x][y - 1] : calculate(matrix, dp, x, y - 1)) + 1);
            if (y < n - 1 && matrix[x][y] > matrix[x][y + 1])
                ans = max(ans, (dp[x][y + 1] > 0 ? dp[x][y + 1] : calculate(matrix, dp, x, y + 1)) + 1);
            dp[x][y] = ans;
            return ans;
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
// @ID: #392
// @Date: 2020/7/27
// @Algorithm: Simple Algorithm
// @Time: O(n)  
// @Space: O(1)
//---------------------------------------------
namespace s392 {
    class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int i = 0, j = 0, a = s.length(), b = t.length();
            while (i < a && j < b) {
                if (s[i] == t[j])
                    i++, j++;
                else
                    j++;
            }
            return (i == a);
        }
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
            for (unsigned int i = 0; i < nums.size(); i++) {
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
// @ID: #410
// @Date: 2020/7/25
// @Algorithm: Dynamic Algorithm
// @Time: O(n log(sum−maxn))
// @Space: O(1)
//---------------------------------------------
namespace s410 {
    class Solution {
    public:
        bool check(vector<int>& nums, int x, int m) {
            long long sum = 0;
            int cnt = 1;
            for (int i = 0; i < int(nums.size()); i++) {
                if (sum + nums[i] > x) {
                    cnt++;
                    sum = nums[i];
                }
                else {
                    sum += nums[i];
                }
            }
            return cnt <= m;
        }

        int splitArray(vector<int>& nums, int m) {
            long long left = 0, right = 0;
            for (int i = 0; i < int(nums.size()); i++) {
                right += nums[i];
                if (left < nums[i]) {
                    left = nums[i];
                }
            }
            while (left < right) {
                long long mid = (left + right) >> 1;
                if (check(nums, int(mid), m)) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            return int(left);
        }
    };
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
// @ID: #497
// @Date: 2020/7/20 
// @Algorithm: Random Algorithm
// @Time: O(n)  O(log n)
// @Space: O(n)
//---------------------------------------------
namespace s497 {
    class Solution {
    public:
        vector<int> prefixSum;
        vector<vector<int>>& rects;
        Solution(vector<vector<int>>& rects) : rects(rects) {
            prefixSum.resize(rects.size());
            prefixSum[0] = (rects[0][2] - rects[0][0] + 1) * (rects[0][3] - rects[0][1] + 1);
            for (unsigned i = 1; i < rects.size(); i++)
                prefixSum[i] = prefixSum[i - 1] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            return;
        }

        vector<int> pick() {
            int l = 0, r = prefixSum.size() - 1, mid = 0;
            int x = rand() % prefixSum[r];
            while (l != r) {
                int mid = (l + r) >> 1;
                if (prefixSum[mid] > x)
                    r = mid;
                else
                    l = mid + 1;
            }
            return { rects[l][0] + (rand() % (rects[l][2] - rects[l][0] + 1)), rects[l][1] + (rand() % (rects[l][3] - rects[l][1] + 1)) };
        }
    };

    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(rects);
     * vector<int> param_1 = obj->pick();
     */
}


//---------------------------------------------
// @ID: #519
// @Date: 2020/7/20 
// @Algorithm: Random Algorithm
// @Time: O(n)  O(log n)
// @Space: O(n)
//---------------------------------------------
namespace s519 {
    class Solution {
    public:

        unordered_map<int, int> m;
        int r, c, n;

        Solution(int n_rows, int n_cols) {
            r = n_rows, c = n_cols, n = r * c;
        }

        vector<int> flip() {
            int k = rand() % n;
            n--;
            int x = m.count(k) ? m[k] : k;
            m[k] = m.count(n) ? m[n] : n;
            return { x / c, x % c };
        }

        void reset() {
            n = c * r;
            m.clear();
        }
    };

    /**
    * Your Solution object will be instantiated and called as such:
    * Solution* obj = new Solution(n_rows, n_cols);
    * vector<int> param_1 = obj->flip();
    * obj->reset();
    */
}


//---------------------------------------------
// @ID: #528
// @Date: 2020/7/19 
// @Algorithm: Random Algorithm
// @Time: O(n)  O(log n)
// @Space: O(n)
//---------------------------------------------
namespace s528 {
    class Solution {
    public:
        vector<int> prefixSum;

        Solution(vector<int>& w) {
            prefixSum.resize(w.size());
            prefixSum[0] = w[0];
            for (unsigned int i = 1; i < w.size(); i++)
                prefixSum[i] = prefixSum[i - 1] + w[i];
            return;
        }

        int pickIndex() {
            int l = 0, r = prefixSum.size() - 1;
            int x = rand() % prefixSum[r];
            while (l != r) {
                int mid = (l + r) >> 1;
                if (x >= prefixSum[mid])
                    l = mid + 1;
                else 
                    r = mid;
            }
            return l;
        }
    };

    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(w);
     * int param_1 = obj->pickIndex();
     */
}


//---------------------------------------------
// @ID: #710
// @Date: 2020/7/20
// @Algorithm:  Blacklist Sampling Algorithm
// @Time: O(b)  O(1)
// @Space: O(b)
//---------------------------------------------
namespace s710 {
    class Solution {
    public:
        unordered_map<int, int> m;
        int l;
        Solution(int n, vector<int> b) {
            l = n - b.size();
            unordered_set<int> s;
            for (int i = l; i < n; i++)
                s.insert(i);
            for (int x : b)
                s.erase(x);
            auto si = s.begin();
            for (int x : b)
                if (x < l)
                    m[x] = *si++;
        }

        int pick() {
            int k = rand() % l;
            return m.count(k) ? m[k] : k;
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
            unsigned int i = 0, j = 0;
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


// TODO
/*
namespace s838 {
    class Solution {
    public:
        string pushDominoes(string dominoes) {
            int i = 0, j = 0, x = 0, y = 0, k = 0, n = dominoes.size();
            while (k < n && dominoes[k] == '.')
                k++;
            if (k < n)
                for (x = 0; x < k; x++)
                    dominoes[x] = dominoes[k];
            while (k < n) {
                i = k, k++;
                while (k < n && dominoes[k] == '.')
                    k++;
                if (k < n) {
                    j = k, x = i + 1, y = j - 1;
                    while (x < y) {
                        dominoes[x++] = dominoes[i];
                        dominoes[y--] = dominoes[j];
                    }
                    if ()

                }
                else {
                    for (x = i + 1; x < n; x++)
                        dominoes[x] = dominoes[i];
                    break;
                }
            }
            return dominoes;
        }
    };
}
*/

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
            unsigned int i = 0, j = 0;
            int k = 0, s = 0, ret = 0, max = 0, min = 0;
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
// @ID: #860
// @Date: 2020/7/21
// @Algorithm: Greedy Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s860 {
    class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int a = 0, b = 0;
            for (unsigned int i = 0; i < bills.size(); i++) {
                switch (bills[i])
                {
                case 5:
                    a++;
                    break;
                case 10:
                    if (--a < 0)
                        return false;
                    b++;
                    break;
                case 20:
                    if (a > 0 && b > 0)
                        a--, b--;
                    else if (a >= 3)
                        a -= 3;
                    else
                        return false;
                    break;
                default:
                    break;
                }
            }
            return true;

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
// @ID: #1025
// @Date: 2020/7/24
// @Algorithm: Simple Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s1025 {
    class Solution {
    public:
        bool divisorGame(int N) {
            return N % 2 == 0;
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


//---------------------------------------------
// @ID: #o11
// @Date: 2020/7/22
// @Algorithm: Binary Search Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace o11 {
    class Solution {
    public:
        int minArray(vector<int>& numbers) {
            int i = 0, j = numbers.size() - 1, mid = 0;
            while (i != j) {
                mid = i + ((j - i) >> 1);
                if (numbers[mid] < numbers[j]) {
                    j = mid;
                }
                else if (numbers[mid] > numbers[j]) {
                    i = mid + 1;;
                }
                else {
                    j--;
                }
            }
            return numbers[i];
        }
    };
}


//---------------------------------------------
// @ID: #o64
// @Date: 2020/7/20
// @Algorithm: Simple Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace o64 {
    class Solution {
    public:
        int sumNums(int n) {
            n && (n += sumNums(n - 1));
            return n;
        }
    };
}
