#pragma once
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <random>
#include <stack>
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


//---------------------------------------------
// @ID: #5
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(n^2)
//---------------------------------------------
namespace s5 {
    class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.length() == 0)
                return "";
            int maxLength = 1, x = 0;
            vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
            for (int i = s.size() - 1; i >= 0; i--) {
                dp[i][i] = true;
                for (int j = i + 1; j < int(s.size()); j++) {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                    if (dp[i][j] && (j - i + 1 > maxLength))
                        maxLength = j - i + 1, x = i;
                }
            }
            return s.substr(x, maxLength);
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
// @ID: #9
// @Date: 2020/9/18
// @Algorithm: Simple Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s9 {
    class Solution {
    public:
        bool isPalindrome(int x) {
            char c[100];
            string s;
            sprintf_s(c, "%d", x);
            s.assign(c);
            reverse(s.begin(), s.end());
            return (s == string(c));
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


// TODO
/*
namespace s14 {
    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int index = 0, size = strs.size();
            while (true) {
                for (int i = 0; i < size; i++) {
                    if (strs[i][index] )

                }
                index++;
            }


        }
    };
}
*/


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


// TODO 
namespace s39 {
    class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            if (candidates.size() == 0)
                return {};
            this->n = candidates.size();
            this->candidates = &candidates;
            this->target = target;
            this->candidateSet.clear();
            this->candidateAnsSet.clear();
        }
    private:
        int n = 0;
        int target = 0;
        vector<int>* candidates;
        int sum;
        vector<int> candidateSet;
        vector<vector<int>> candidateAnsSet;

        void DFS(int c) {
            // if ()

            candidateSet.push_back((*candidates)[c]);
            // if ()

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
// @ID: #53
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s53 {
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int dp = nums[0], ans = nums[0];
            if (nums.size() == 0)
                return 0;
            for (int i = 1; i < int(nums.size()); i++) {
                dp = max(dp + nums[i], nums[i]);
                ans = max(ans, dp);
            }
            return ans;
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
// @ID: #62
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(mn)
// @Space: O(mn)
//---------------------------------------------
namespace s62 {
    class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                dp[i][0] = 1;
            for (int j = 0; j < n; j++)
                dp[0][j] = 1;

            for (int i = 1; i < m; i++)
                for (int j = 1; j < n; j++)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            
            return dp[m - 1][n - 1];
        }
    };
}


//---------------------------------------------
// @ID: #63
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(mn)
// @Space: O(mn)
//---------------------------------------------
namespace s63 {
    class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
                return 1;
            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                if (obstacleGrid[i][0])
                    break;
                dp[i][0] = 1;
            }
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[0][j])
                    break;
                dp[0][j] = 1;
            }

            for (int i = 1; i < m; i++)
                for (int j = 1; j < n; j++)
                    if (!obstacleGrid[i][j])
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            
            return dp[m - 1][n - 1];
        }
    };
}


//---------------------------------------------
// @ID: #64
// @Date: 2020/7/23
// @Algorithm: Dynamic Programming Algorithm
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
// @ID: #70
// @Date: 2020/7/31
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s70 {
    class Solution {
    public:
        int climbStairs(int n) {
            vector<int> dp(n + 1);
            if (n == 1)
                return 1;
            if (n == 2)
                return 2;
            dp[1] = 1, dp[2] = 2;
            for (int i = 3; i <= n; i++)
                dp[i] = dp[i - 1] + dp[i - 2];
            return dp[n];
        }
    };
}


//---------------------------------------------
// @ID: #72
// @Date: 2020/9/18
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(mn)
// @Space: O(mn)
//---------------------------------------------
namespace s72 {
    class Solution {
    public:
        int minDistance(string word1, string word2) {
            int l1 = word1.length(), l2 = word2.length();
            vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
            
            for (int i = 1; i <= l1; i++) {
                dp[i][0] = i;
            }

            for (int j = 1; j <= l2; j++) {
                dp[0][j] = j;
            }

            for (int i = 1; i <= l1; i++) {
                for (int j = 1; j <= l2; j++) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));
                }
            }

            return dp[l1][l2];
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
// @ID: #91
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s91 {
    class Solution {
    public:
        int numDecodings(string s) {
            if (s.length() == 0 || s[0] == '0')
                return 0;
            int dp1 = 1, dp2 = 1, dp3 = 0;
            for (int i = 1; i < int(s.length()); i++) {
                if (s[i] == '0') {
                    if (s[i - 1] == '1' || s[i - 1] == '2')
                        dp3 = dp2, dp2 = dp1, dp1 = dp3;
                    else
                        dp1 = dp2, dp2 = 0;
                }
                else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                    dp2 = dp2 + dp1, dp1 = dp2 - dp1;
                }
                else {
                    dp1 = dp2;
                }
            }
            return dp2;
        }
    };
}


//---------------------------------------------
// @ID: #93
// @Date: 2020/8/9
// @Algorithm: String Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s93 {
    class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            if (s.size() < 4 || s.size() > 12)
                return {};
            int n = s.size(), i = 0, j = 0, k = 0, l = 0;
            string s1, s2, s3, s4;
            vector<string> ans;
            for (i = 1; i <= 3; i++) {
                s1 = s.substr(0, i);
                if (!isValid(s1))
                    continue;
                for (j = 1; j <= 3; j++) {
                    if (i >= n)
                        continue;
                    s2 = s.substr(i, j);
                    if (!isValid(s2))
                        continue;
                    for (k = 1; k <= 3; k++) {
                        if (i + j + k >= n)
                            continue;
                        s3 = s.substr(i + j, k);
                        if (!isValid(s3))
                            continue;
                        s4 = s.substr(i + j + k);
                        if (!isValid(s4))
                            continue;
                        ans.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                    }
                }
            }
            return ans;
        }
    private:
        bool isValid(string &s) {
            if (s.size() == 1)
                return true;
            if (s.size() == 2)
                return s[0] != '0';
            if (s.size() == 3) {
                if (s[0] == '1')
                    return true;
                if (s[0] == '2')
                    return s[1] < '5' || (s[1] == '5' && s[2] <= '5');
            }
            return false;
        }
    };
}


//---------------------------------------------
// @ID: #94
// @Date: 2020/8/7
// @Algorithm: Tree Algorithm | Recursion Algorithm 
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s94 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            ans.clear();
            _inorderTraversal(root);
            return ans;
        }
    private:
        vector<int> ans;

        void _inorderTraversal(TreeNode* root) {
            if (!root)
                return;
            _inorderTraversal(root->left);
            ans.push_back(root->val);
            _inorderTraversal(root->right);
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
// @ID: #96
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(n)
//---------------------------------------------
namespace s96 {
    class Solution {
    public:
        int numTrees(int n) {
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= i; j++)
                    dp[i] += dp[j - 1] * dp[i - j];
            return dp[n];
        }
    };
}


//---------------------------------------------
// @ID: #98
// @Date: 2020/8/7
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s98 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            if (!root)
                return true;
            int currentMinVal = root->val, currentMaxVal = root->val;
            if (root->left) {
                if (!isValidBST(root->left) || maxVal >= root->val)
                    return false;
                currentMinVal = minVal;
            }

            if (root->right) {
                if (!isValidBST(root->right) || minVal <= root->val)
                    return false;
                currentMaxVal = maxVal;
            }
            
            minVal = currentMinVal;
            maxVal = currentMaxVal;
            return true;
        }

    private:
        int minVal = 0, maxVal = 0;
    };
}


//---------------------------------------------
// @ID: #99
// @Date: 2020/8/8
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s99 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        void recoverTree(TreeNode* root) {
            vector<int> nums;
            inorder(root, nums);
            pair<int, int> swapped = findTwoSwapped(nums);
            recover(root, 2, swapped.first, swapped.second);
        }

    private:
        void inorder(TreeNode* root, vector<int>& nums) {
            if (root == nullptr) {
                return;
            }
            inorder(root->left, nums);
            nums.push_back(root->val);
            inorder(root->right, nums);
        }

        pair<int, int> findTwoSwapped(vector<int>& nums) {
            int n = nums.size();
            int x = -1, y = -1;
            for (int i = 0; i < n - 1; ++i) {
                if (nums[i + 1] < nums[i]) {
                    y = nums[i + 1];
                    if (x == -1) {
                        x = nums[i];
                    }
                    else break;
                }
            }
            return { x, y };
        }

        void recover(TreeNode* r, int count, int x, int y) {
            if (r != nullptr) {
                if (r->val == x || r->val == y) {
                    r->val = r->val == x ? y : x;
                    if (--count == 0) {
                        return;
                    }
                }
                recover(r->left, count, x, y);
                recover(r->right, count, x, y);
            }
        }
    };
}

//---------------------------------------------
// @ID: #100
// @Date: 2020/8/7
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s100 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (!p || !q)
                return !p && !q;
            return p->val == q->val ? isSameTree(p->left, q->left) && isSameTree(p->right, q->right) : false;
        }
    };
}


//---------------------------------------------
// @ID: #101
// @Date: 2020/8/8
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s101 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            return root ? isSymmetric(root->left, root->right) : true;
        }

    private:
        bool isSymmetric(TreeNode* left, TreeNode* right) {
            if (!left || !right)
                return !left && !right;
            return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
    };
}


//---------------------------------------------
// @ID: #102
// @Date: 2020/8/8
// @Algorithm: Tree Algorithm | Queue Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s102 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            if (!root)
                return {};
            int n = 1;
            vector<vector<int>> ans;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                vector<int> nodes;
                TreeNode* node = nullptr;
                int number = n;
                for (int i = 0; i < number; i++) {
                    node = q.front();
                    q.pop();
                    n--;
                    nodes.push_back(node->val);
                    if (node->left) {
                        q.push(node->left);
                        n++;
                    }   
                    if (node->right) {
                        q.push(node->right);
                        n++;
                    }
                }
                ans.push_back(nodes);
            }
            return ans;
        }
    };
}


//---------------------------------------------
// @ID: #103
// @Date: 2020/8/8
// @Algorithm: Tree Algorithm | Queue Algorithm | Stack Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s103 {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if (!root)
                return {};
            int depth = 1;
            vector<vector<int>> ans;
            stack<TreeNode*> s1;
            stack<TreeNode*> s2;
            s1.push(root);
            while (true) {
                if (depth & 1) {
                    if (s1.empty())
                        break;
                    vector<int> nodes;
                    TreeNode* node = nullptr;
                    while(!s1.empty()){
                        node = s1.top();
                        s1.pop();
                        nodes.push_back(node->val);
                        if (node->left)
                            s2.push(node->left);
                        if (node->right)
                            s2.push(node->right);
                    }
                    ans.push_back(nodes);
                }
                else {
                    if (s2.empty())
                        break;
                    vector<int> nodes;
                    TreeNode* node = nullptr;
                    while (!s2.empty()) {
                        node = s2.top();
                        s2.pop();
                        nodes.push_back(node->val);
                        if (node->right)
                            s1.push(node->right);
                        if (node->left)
                            s1.push(node->left);
                    }
                    ans.push_back(nodes);
                }
                depth++;
            }
            return ans;
        }
    };
}


//---------------------------------------------
// @ID: #104
// @Date: 2020/7/28
// @Algorithm: Tree Algorithm
// @Time: O(log n)
// @Space: O(1)
//---------------------------------------------
namespace s104 {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (!root)
                return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    };
}


//---------------------------------------------
// @ID: #105
// @Date: 2020/8/8
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s105 {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.size() != inorder.size())
                return nullptr;
            int n = preorder.size();
            this->preorder = &preorder;
            this->inorder = &inorder;
            return buildPartTree(0, n - 1, 0, n - 1);
        }
    private:
        vector<int>* preorder = nullptr, * inorder = nullptr;

        // [requires] preorderJ - preorderI == inorderJ - inorderI
        TreeNode* buildPartTree(const int preorderI, const int preorderJ, const int inorderI, const int inorderJ) {
            if (preorderI > preorderJ)
                return nullptr;
            TreeNode* root = new TreeNode((*preorder)[preorderI]);
            int inorderX = inorderI;
            while ((*inorder)[inorderX] != root->val) inorderX++;
            root->left = buildPartTree(
                preorderI + 1, preorderI + inorderX - inorderI,
                inorderI, inorderX - 1
            );
            root->right = buildPartTree(
                preorderJ - inorderJ + inorderX + 1, preorderJ,
                inorderX + 1, inorderJ
            );
            return root;
        }
    };
}


//---------------------------------------------
// @ID: #114
// @Date: 2020/8/2
// @Algorithm: Tree Algorithm | Recursive Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s114 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        void flatten(TreeNode* root) {
            if (root == nullptr)
                return;
            TreeNode* currentEnd = root, * left = root->left, * right = root->right;
            root->left = nullptr, root->right = nullptr;
            if (left) {
                flatten(left);
                currentEnd->right = begin;
                currentEnd = end;
            }
            if (right) {
                flatten(right);
                currentEnd->right = begin;
                currentEnd = end;
            }
            begin = root, end = currentEnd;
        }
    private:
        TreeNode *begin = nullptr, *end = nullptr;
    };
}


//---------------------------------------------
// @ID: #120
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(n)
//---------------------------------------------
namespace s120 {
    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            if (triangle.size() == 0)
                return 0;
            int n = triangle.size(), minTotal = INT_MAX;
            vector<int> dp(n, INT_MAX);
            dp[0] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i ; j > 0; j--) {
                    dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                }
                dp[0] += triangle[i][0];
            }
            for (int i = 0; i < n; i++)
                minTotal = min(minTotal, dp[i]);
            return minTotal;
        }
    };
}


//---------------------------------------------
// @ID: #121
// @Date: 2020/7/31
// @Algorithm: Greedy Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s121 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.size() == 0)
                return 0;
            int maxProfit = 0, minPrice = prices[0];
            for (int i = 1; i < int(prices.size()); i++) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
                minPrice = min(minPrice, prices[i]);
            }
            return maxProfit;
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
// @ID: #130
// @Date: 2020/8/11
// @Algorithm: Search Algorithm
// @Time: O(nm)
// @Space: O(nm)
//---------------------------------------------
namespace s130 {
    class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            if (board.size() == 0 || board[0].size() == 0)
                return;
            n = board.size();
            m = board[0].size();
            this->board = &board;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (board[i][j] == 'O')
                        board[i][j] = ' ';
            for (int i = 0; i < n; i++) {
                search(i, 0);
                search(i, m - 1);
            }
            for (int j = 0; j < m; j++) {
                search(0, j);
                search(n - 1, j);
            }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (board[i][j] == ' ')
                        board[i][j] = 'X';
            return;
        }
    private:
        int n = 0, m = 0;
        vector<vector<char>>* board = nullptr;
        void search(int x, int y) {
            if ((*board)[x][y] != ' ')
                return;
            (*board)[x][y] = 'O';
            if (x + 1 < n)
                search(x + 1, y);
            if (x - 1 >= 0)
                search(x - 1, y);
            if (y + 1 < m)
                search(x, y + 1);
            if (y - 1 >= 0)
                search(x, y - 1);
        }
    };
}


//---------------------------------------------
// @ID: #133
// @Date: 2020/8/12
// @Algorithm: Graph Algorithm | Queue Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s133 {
    class Node {
    public:
        int val;
        vector<Node*> neighbors;

        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }

        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }

        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };

    class Solution {
    public:
        Node* cloneGraph(Node* node) {
            if (!node)
                return nullptr;
            Node* n = nullptr;
            queue<Node*> queList;
            unordered_map<Node*, Node*> mapList;
            mapList[node] = new Node(node->val);
            queList.push(node);
            while (!queList.empty()) {
                n = queList.front();
                queList.pop();
                for (Node* neighbor : n->neighbors) {
                    if (mapList.find(neighbor) == mapList.end()) {
                        mapList[neighbor] = new Node(neighbor->val);
                        queList.push(neighbor);   
                    }
                    mapList[n]->neighbors.push_back(mapList[neighbor]);
                }
            }
            return mapList[node];
        }
    };
}


//---------------------------------------------
// @ID: #139
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(mn)
// @Space: O(n)
//---------------------------------------------
namespace s139 {
    class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            int n = s.length(), m = wordDict.size(), l = 0;
            vector<bool> dp(n, false);
            for (int i = 0; i < n; i++) {
                for (auto str : wordDict) {
                    l = str.length();
                    if ((i + 1 >= l) && (s.substr(i + 1 - l, l) == str) && ((i + 1 - l == 0) || dp[i- l])) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[n - 1];
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
// @ID: #152
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s152 {
    class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            if (nums.size() == 0)
                return 0;
            if (nums.size() == 1)
                return nums[0];
            int n = nums.size(), dp_max = 0, dp_min = 0, dp_temp = 0, maxProduct = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] >= 0) {
                    dp_max = dp_max > 0 ? dp_max * nums[i] : nums[i];
                    dp_min = dp_min * nums[i];
                }
                else {
                    dp_temp = dp_max;
                    dp_max = dp_min * nums[i];
                    dp_min = dp_temp > 0 ? dp_temp * nums[i] : nums[i];
                }
                maxProduct = max(maxProduct, dp_max);
            }
            return maxProduct;
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
// @ID: #198
// @Date: 2020/7/31
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s198 {
    class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if (n == 0)
                return 0;
            int dp_done = nums[0], dp_undo = 0, temp = 0;
            for (int i = 1; i < n; i++) {
                temp = dp_done;
                dp_done = dp_undo + nums[i];
                dp_undo = max(dp_undo, temp);
            }
            return max(dp_done, dp_undo);
        }
    };
}


//---------------------------------------------
// @ID: #207
// @Date: 2020/8/4
// @Algorithm: DFS Algorithm 
// @Time: O(n+m)
// @Space: O(n+m)
//---------------------------------------------
namespace s207 {
    class Solution {
    private:
        vector<vector<int>> edges;
        vector<int> visited;
        bool valid = true;

    public:
        void dfs(int u) {
            visited[u] = 1;
            for (int v : edges[u]) {
                if (visited[v] == 0) {
                    dfs(v);
                    if (!valid) {
                        return;
                    }
                }
                else if (visited[v] == 1) {
                    valid = false;
                    return;
                }
            }
            visited[u] = 2;
        }

        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            edges.resize(numCourses);
            visited.resize(numCourses);
            for (const auto& info : prerequisites) {
                edges[info[1]].push_back(info[0]);
            }
            for (int i = 0; i < numCourses && valid; ++i) {
                if (!visited[i]) {
                    dfs(i);
                }
            }
            return valid;
        }
    };
}


//---------------------------------------------
// @ID: #213
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s213 {
    class Solution {
    public:
        int rob(vector<int>& nums) {
            if (nums.size() == 0)
                return 0;
            if (nums.size() == 1)
                return nums[0];
            if (nums.size() == 2)
                return max(nums[0], nums[1]);
            if (nums.size() == 3) {
                int temp = max(nums[0], nums[1]);
                return max(temp, nums[2]);
            }

            int n = nums.size();
            int dp_done_0 = nums[1], dp_undo_0 = 0, dp_done_1 = nums[0] + nums[2], dp_undo_1 = nums[0],  dp_temp = 0;
            
            for (int i = 2; i < n; i++) {
                dp_temp = dp_done_0;
                dp_done_0 = dp_undo_0 + nums[i];
                dp_undo_0 = max(dp_undo_0, dp_temp);
            }
            for (int i = 3; i < n - 1; i++) {
                dp_temp = dp_done_1;
                dp_done_1 = dp_undo_1 + nums[i];
                dp_undo_1 = max(dp_undo_1, dp_temp);
            }
            dp_temp = max(dp_done_0, dp_undo_0);
            dp_temp = max(dp_temp, dp_done_1);
            dp_temp = max(dp_temp, dp_undo_1);
            return dp_temp;
        }
    };
}


//---------------------------------------------
// @ID: #263
// @Date: 2020/8/2
// @Algorithm: Simple Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s263 {
    class Solution {
    public:
        bool isUgly(int num) {
            if (num == 0)
                return false;
            while (num % 2 == 0) num /= 2;
            while (num % 3 == 0) num /= 3;
            while (num % 5 == 0) num /= 5;
            return num == 1;
        }
    };
}


//---------------------------------------------
// @ID: #264
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s264 {
    class Solution {
    public:
        int nthUglyNumber(int n) {
            if (n == 1)
                return 1;
            int i = 0, point_2 = 1, point_3 = 1, point_5 = 1, temp_2 = 0, temp_3 = 0, temp_5 = 0;
            vector<int> dp(n + 1);
            dp[1] = 1, i = 2;
            while (i <= n) {
                temp_2 = dp[point_2] * 2;
                temp_3 = dp[point_3] * 3;
                temp_5 = dp[point_5] * 5;
                if ((temp_2 <= temp_3) && (temp_2 <= temp_5)) {
                    dp[i] = temp_2;
                    point_2++;
                }
                else if (temp_3 <= temp_5) {
                    dp[i] = temp_3;
                    point_3++;
                }
                else {
                    dp[i] = temp_5;
                    point_5++;
                }
                if (dp[i] != dp[i - 1])
                    i++;
            }
            return dp[n];
        }
    };
}


//---------------------------------------------
// @ID: #279
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(n^1.5)
//---------------------------------------------
namespace s279 {
    class Solution {
    public:
        int numSquares(int n) {
            int k = 0;
            vector<int> dp(n + 1);
            dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                dp[i] = INT_MAX;
                for (int j = int(sqrt(i)); j >= 1; j--) {
                    k = i - j * j;
                    if (dp[k] != INT_MAX)
                        dp[i] = min(dp[i], dp[k] + 1);
                }
            }
            return dp[n];
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
// @ID: #300
//---------------------------------------------
namespace s300 {
    class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            // TODO
        }
    };
}


//---------------------------------------------
// @ID: #303
// @Date: 2020/8/1
// @Algorithm: Simple Algorithm | Using Buffer
// @Time: O(n) -> O(1)
// @Space: O(n)
//---------------------------------------------
namespace s303 {
    class NumArray {
    public:
        NumArray(vector<int>& nums) : nums(nums) {
            numsSize = nums.size();
            prefixSum.resize(numsSize);
            prefixBufferIndex = 0;
            if (numsSize > 0)
                prefixSum[0] = nums[0];
        }

        int sumRange(int i, int j) {
            if (j > prefixBufferIndex) {
                for (int x = prefixBufferIndex + 1; x <= j; x++)
                    prefixSum[x] = prefixSum[x - 1] + nums[x];
                prefixBufferIndex = j;
            }
            return prefixSum[j] - prefixSum[i] + nums[i];
        }
    private:
        int numsSize = 0;
        int prefixBufferIndex = 0;
        vector<int>& nums;
        vector<int>prefixSum;
    };

    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray* obj = new NumArray(nums);
     * int param_1 = obj->sumRange(i,j);
     */
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
// @ID: #322
// @Date: 2020/8/2 
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(mn)
// @Space: O(n)
//---------------------------------------------
namespace s322 {
    class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n = amount, m = coins.size(), k = 0;
            vector<int> dp(n + 1);
            for (int i = 1; i <= n; i++) {
                dp[i] = INT_MAX;
                for (int j = 0; j < m; j++) {
                    k = i - coins[j];
                    if (k >= 0 && dp[k] != INT_MAX)
                        dp[i] = min(dp[i], dp[k] + 1);
                }
            }
            return dp[n] != INT_MAX ? dp[n] : -1;
        }
    };
}


//---------------------------------------------
// @ID: #329
// @Date: 2020/7/26
// @Algorithm: Dynamic Programming Algorithm
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
// @ID: #336
// @Date: 2020/8/6
// @Algorithm: Tree Algorithm | Manacher Algorithm
// @Time: O(mn)
// @Space: O(mn)
//---------------------------------------------
namespace s336 {
    struct Trie {
        struct node {
            int ch[26];
            int flag;
            node() {
                flag = -1;
                memset(ch, 0, sizeof(ch));
            }
        };

        vector<node> tree;

        Trie() { tree.emplace_back(); }

        void insert(string& s, int id) {
            int len = s.length(), add = 0;
            for (int i = 0; i < len; i++) {
                int x = s[i] - 'a';
                if (!tree[add].ch[x]) {
                    tree.emplace_back();
                    tree[add].ch[x] = tree.size() - 1;
                }
                add = tree[add].ch[x];
            }
            tree[add].flag = id;
        }

        vector<int> query(string& s) {
            int len = s.length(), add = 0;
            vector<int> ret(len + 1, -1);
            for (int i = 0; i < len; i++) {
                ret[i] = tree[add].flag;
                int x = s[i] - 'a';
                if (!tree[add].ch[x]) {
                    return ret;
                }
                add = tree[add].ch[x];
            }
            ret[len] = tree[add].flag;
            return ret;
        }
    };

    class Solution {
    public:
        vector<pair<int, int>> manacher(string& s) {
            int n = s.length();
            string tmp = "#";
            tmp += s[0];
            for (int i = 1; i < n; i++) {
                tmp += '*';
                tmp += s[i];
            }
            tmp += '!';
            int m = n * 2;
            vector<int> len(m);
            vector<pair<int, int>> ret(n);
            int p = 0, maxn = -1;
            for (int i = 1; i < m; i++) {
                len[i] = maxn >= i ? min(len[2 * p - i], maxn - i) : 0;
                while (tmp[i - len[i] - 1] == tmp[i + len[i] + 1]) {
                    len[i]++;
                }
                if (i + len[i] > maxn) {
                    p = i, maxn = i + len[i];
                }
                if (i - len[i] == 1) {
                    ret[(i + len[i]) / 2].first = 1;
                }
                if (i + len[i] == m - 1) {
                    ret[(i - len[i]) / 2].second = 1;
                }
            }
            return ret;
        }

        vector<vector<int>> palindromePairs(vector<string>& words) {
            Trie trie1, trie2;

            int n = words.size();
            for (int i = 0; i < n; i++) {
                trie1.insert(words[i], i);
                string tmp = words[i];
                reverse(tmp.begin(), tmp.end());
                trie2.insert(tmp, i);
            }

            vector<vector<int>> ret;
            for (int i = 0; i < n; i++) {
                const vector<pair<int, int>>& rec = manacher(words[i]);

                const vector<int>& id1 = trie2.query(words[i]);
                reverse(words[i].begin(), words[i].end());
                const vector<int>& id2 = trie1.query(words[i]);

                int m = words[i].size();

                int all_id = id1[m];
                if (all_id != -1 && all_id != i) {
                    ret.push_back({ i, all_id });
                }
                for (int j = 0; j < m; j++) {
                    if (rec[j].first) {
                        int left_id = id2[m - j - 1];
                        if (left_id != -1 && left_id != i) {
                            ret.push_back({ left_id, i });
                        }
                    }
                    if (rec[j].second) {
                        int right_id = id1[j];
                        if (right_id != -1 && right_id != i) {
                            ret.push_back({ i, right_id });
                        }
                    }
                }
            }
            return ret;
        }
    };
}


//---------------------------------------------
// @ID: #337
// @Date: 2020/8/5
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s337 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    class Solution {
    public:
        int rob(TreeNode* root) {
            if (!root) {
                dp_done = 0, dp_undo = 0;
                return 0;
            }

            int dp_done_temp = root->val, dp_undo_temp = 0;

            dp_undo_temp += rob(root->left);
            dp_done_temp += dp_undo;

            dp_undo_temp += rob(root->right);
            dp_done_temp += dp_undo;

            dp_done = dp_done_temp, dp_undo = dp_undo_temp;
            return max(dp_done_temp, dp_undo_temp);
        }
    private:
        int dp_done = 0, dp_undo = 0;
    };

}

//---------------------------------------------
// @ID: #338
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s338 {
    class Solution {
    public:
        vector<int> countBits(int num) {
            int n = num;
            vector<int> dp(n + 1);
            for (int i = 1; i <= n; i++)
                dp[i] = dp[i >> 1] + (i & 1);
            return dp;
        }
    };
}


//---------------------------------------------
// @ID: #343
// @Date: 2020/7/30
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(n)
//---------------------------------------------
namespace s343 {
    class Solution {
    public:
        int integerBreak(int n) {
            vector<int> dp(n + 1);
            for (int i = 0; i < n; i++) {
                dp[i] = i;
                for (int j = 1; j <= i / 2; j++)
                    dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
            dp[n] = 0;
            for (int j = 1; j <= n / 2; j++)
                dp[n] = max(dp[n], dp[j] * dp[n - j]);
            return dp[n];
        }
    };
}


//---------------------------------------------
// @ID: #368
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(n)
//---------------------------------------------
namespace s368 {
    class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            if (nums.size() == 0)
                return {};
            int n = nums.size(), i = 0, maxSize = 0, maxIndex = 0;
            vector<int> dp(n);
            sort(nums.begin(), nums.end());
            for (i = 0; i < n; i++) {
                dp[i] = 1;
                for (int j = 0; j < i; j++) {
                    if (nums[i] % nums[j] == 0)
                        dp[i] = max(dp[i], dp[j] + 1);
                }
                if (dp[i] > maxSize) {
                    maxSize = dp[i];
                    maxIndex = i;
                }
            }
            vector<int> ansSet;
            ansSet.push_back(nums[maxIndex]);
            i = maxIndex;
            maxSize--;
            while (i > 0) {
                i--;
                if ((nums[maxIndex] % nums[i] == 0) && (dp[i] == maxSize)) {
                    ansSet.push_back(nums[i]);
                    maxIndex = i;
                    maxSize--;
                }
            }
            return ansSet;
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
// @ID: #377
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(mn)
// @Space: O(n)
//---------------------------------------------
namespace s377 {
    class Solution {
    public:
        int combinationSum4(vector<int>& nums, int target) {
            int n = target, m = nums.size();
            vector<long> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 1; i <= n; i++)
                for (int j = 0; j < m; j++)
                    if (i >= nums[j]) {
                        dp[i] += dp[i - nums[j]];
                        dp[i] %= INT_MAX;
                    }
            return int(dp[n]);
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
// @Algorithm: Dynamic Programming Algorithm
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
// @ID: #413
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s413 {
    class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& A) {
            if (A.size() == 0)
                return 0;
            int n = A.size(), sum = 0;
            vector<int> dp(n);
            for (int i = 2; i < n; i++)
                if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                    dp[i] = dp[i - 1] + 1;
                    sum += dp[i];
                }
            return sum;

        }
    };
}


//---------------------------------------------
// @ID: #415
// @Date: 2020/8/3
// @Algorithm: Simple Algorithm
// @Time: O(max(i,j))
// @Space: O(1)
//---------------------------------------------
namespace s415 {
    class Solution {
    public:
        string addStrings(string num1, string num2) {
            int i = num1.length() - 1, j = num2.length() - 1, add = 0;
            string ans = "";
            while (i >= 0 || j >= 0 || add != 0) {
                int x = i >= 0 ? num1[i] - '0' : 0;
                int y = j >= 0 ? num2[j] - '0' : 0;
                int result = x + y + add;
                ans.push_back('0' + result % 10);
                add = result / 10;
                i -= 1;
                j -= 1;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
}


//---------------------------------------------
// @ID: #416
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(?)
// @Space: O(n)
//---------------------------------------------
namespace s416 {
    class Solution {
    public:
        vector<int> *nums;
        vector<int> prefixSum;
        bool canPartition(vector<int>& nums) {
            if (nums.size() == 0)
                return true;
            int n = nums.size(), sum = 0;
            sort(nums.begin(), nums.end());
            this->nums = &nums;
            prefixSum.resize(n);
            prefixSum[0] = nums[0];
            for (int i = 1; i < n; i++)
                prefixSum[i] = prefixSum[i - 1] + nums[i];
            if (prefixSum[n - 1] & 1)
                return false;
            return dpCheck(n - 1, prefixSum[n - 1] >> 1);
        }
    private:
        bool dpCheck(int k, int x) {
            if (x <= 0 || prefixSum[k] < x)
                return false;
            if (k == 0)
                return (*nums)[k] == x;
            else
                return dpCheck(k - 1, x - (*nums)[k]) || dpCheck(k - 1, x);
        };
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
// @ID: #509
// @Date: 2020/8/8
// @Algorithm: Math Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s509 {
    class Solution {
    public:
        int fib(int n) {
            if (n <= 0)
                return 0;
            int x = 0, y = 1;
            for (int i = 2; i <= n; i++) {
                y = y + x;
                x = y - x;
                y %= 1000000007;
            }
            return y;
        }
    };
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
// @ID: #530
// @Date: 2020/8/8 
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s530 {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int getMinimumDifference(TreeNode* root) {
            if (!root)
                return 0;
            minDiff = INT_MAX;
            lastValOK = false;
            inorderBST(root);
            return minDiff;
        }

    private:
        int minDiff = INT_MAX, lastVal = 0;
        bool lastValOK = false;
        void inorderBST(TreeNode* root) {
            if (!root)
                return;
            inorderBST(root->left);
            if (lastValOK)
                minDiff = min(minDiff, root->val - lastVal);
            else
                lastValOK = true;
            lastVal = root->val;
            inorderBST(root->right);
            return;
        }
    };
}


//---------------------------------------------
// @ID: #538
// @Date: 2020/9/21
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s538 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode* convertBST(TreeNode* root) {
            sum = 0;
            _bstToGst(root);
            return root;
        }
    private:
        int sum = 0, val = 0;

        void _bstToGst(TreeNode* root) {
            if (!root)
                return;
            _bstToGst(root->right);
            val = root->val;
            root->val += sum;
            sum += val;
            _bstToGst(root->left);
            return;
        }
    };
}


namespace s632 {
    // TODO
}


//---------------------------------------------
// @ID: #687
// @Date: 2020/7/31
// @Algorithm: Recursion Algorithm
// @Time: O(n)
// @Space: O(logn)
//---------------------------------------------
namespace s687{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int longestUnivaluePath(TreeNode* root) {
            ans = 0;
            searchTree(root);
            return ans;
        }
    private:
        int ans = 0;
        int searchTree(TreeNode* root) {
            if (!root)
                return 0;
            int left = searchTree(root->left) + 1;
            bool bleft = root->left && root->val == root->left->val;
            int right = searchTree(root->right) + 1;
            bool bright = root->right && root->val == root->right->val;
            if (!bleft)
                left = 0;
            if (!bright)
                right = 0;
            ans = max(ans, left + right);
            return max(left, right);
        }
    };
}


//---------------------------------------------
// @ID: #696
// @Date: 2020/8/10
// @Algorithm: Simple Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s696 {
    class Solution {
    public:
        int countBinarySubstrings(string s) {
            if (s.size() == 0)
                return 0;
            int n = s.size(), a = 0, b = 0, i = 0, ans = 0;
            while (i < n) {
                char c = s[i++];
                b = 1;
                while (i < n && s[i] == c)
                    b++, i++;
                ans += min(a, b);
                a = b;
            }
            return ans;
        }
    };
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
// @ID: #746
// @Date: 2020/7/31 
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s746 {
    class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int length = cost.size();
            vector<int> dp(length + 1);
            dp[0] = cost[0], dp[1] = cost[1];
            for (int i = 2; i < length; i++)
                dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
            return min(dp[length - 1], dp[length - 2]);
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


//---------------------------------------------
// @ID: #779
// @Date: 2020/8/8 
// @Algorithm: Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s779 {
    class Solution {
    public:
        int kthGrammar(int N, int K) {
            return N == 1 ? 0 : kthGrammar(N - 1, (K + 1) >> 1) == 1 ? K & 1 : ~K & 1;
        }
    };
}


//---------------------------------------------
// @ID: #783
// @Date: 2020/8/8 
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s783 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int minDiffInBST(TreeNode* root) {
            if (!root)
                return 0;
            minDiff = INT_MAX;
            lastValOK = false;
            inorderBST(root);
            return minDiff;
        }

    private:
        int minDiff = INT_MAX, lastVal = 0;
        bool lastValOK = false;
        void inorderBST(TreeNode* root) {
            if (!root)
                return;
            inorderBST(root->left);
            if (lastValOK)
                minDiff = min(minDiff, root->val - lastVal);
            else
                lastValOK = true;
            lastVal = root->val;
            inorderBST(root->right);
            return;
        }
    };
}


//---------------------------------------------
// @ID: #794
// @Date: 2020/8/8 
// @Algorithm: Simple Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace s794 {
    class Solution {
    public:
        bool validTicTacToe(vector<string>& board) {
            int playerStep1 = 0, playerStep2 = 0;
            bool playerWon1 = false, playerWon2 = false;
            
            for (auto s : board) {
                for (auto c : s) {
                    if (c == 'X')
                        playerStep1++;
                    else if (c == 'O')
                        playerStep2++;
                    else if (c != ' ')
                        return false;
                }
            }
            if (playerStep1 != playerStep2 && playerStep1 != playerStep2 + 1) {
                return false;
            }
            for (int i = 0; i <= 2; i++) {
                if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
                    if (playerWon2)
                        return false;
                    playerWon1 = true;
                }
                if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') {
                    if (playerWon2)
                        return false;
                    playerWon1 = true;
                }
                if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
                    if (playerWon1)
                        return false;
                    playerWon2 = true;
                }
                if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') {
                    if (playerWon1)
                        return false;
                    playerWon2 = true;
                } 
            }
            if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
                if (playerWon2)
                    return false;
                playerWon1 = true;
            }
            if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
                if (playerWon1)
                    return false;
                playerWon2 = true;
            }
            if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
                if (playerWon2)
                    return false;
                playerWon1 = true;
            }
            if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
                if (playerWon1)
                    return false;
                playerWon2 = true;
            }
            return !((playerWon1 && playerStep1 != playerStep2 + 1) || (playerWon2 && playerStep1 != playerStep2));
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
// @ID: #931
// @Date: 2020/8/4
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(n^2)
//---------------------------------------------
namespace s931 {
    class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& A) {
            if (A.size() == 0)
                return 0;
            int n = A.size(), temp = 0;
            vector<vector<int>> dp(n, vector<int>(n));
            for (int j = 0; j < n; j++)
                dp[0][j] = A[0][j];
            for (int i = 1; i < n; i++) {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + A[i][0];
                dp[i][n - 1] = min(dp[i - 1][n - 2], dp[i - 1][n - 1]) + A[i][n - 1];
                for (int j = 1; j < n - 1; j++) {
                    temp = min(dp[i - 1][j - 1], dp[i - 1][j + 1]);
                    dp[i][j] = min(dp[i - 1][j], temp) + A[i][j];
                }
            }
            temp = dp[n - 1][0];
            for (int i = 1; i < n; i++)
                temp = min(temp, dp[n - 1][i]);
            return temp;
        }
    };
}

//---------------------------------------------
// @ID: #938
// @Date: 2020/8/8
// @Algorithm: Tree Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s938 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int rangeSumBST(TreeNode* root, int L, int R) {
            this->L = L;
            this->R = R;
            this->rangeSum = 0;
            inorder(root);
            return rangeSum;
        }
    private:
        int L = 0, R = 0, rangeSum = 0;
        
        void inorder(TreeNode* root) {
            if (!root)
                return;
            inorder(root->left);
            if (root->val >= L && root->val <= R)
                rangeSum += root->val;
            inorder(root->right);
            return;
        }
    };
}


//---------------------------------------------
// @ID: #978
// @Date: 2020/8/4
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s978 {
    class Solution {
    public:
        int maxTurbulenceSize(vector<int>& A) {
            if (A.size() == 0)
                return 0;
            int n = A.size(), maxSize = 1;
            int dpUp = 1, dpDown = 1;
            for (int i = 1; i < n; i++) {
                if (A[i] > A[i - 1]) {
                    dpDown = dpUp + 1;
                    dpUp = 1;
                    maxSize = max(maxSize, dpDown);
                }
                else if (A[i] < A[i - 1]) {
                    dpUp = dpDown + 1;
                    dpDown = 1;
                    maxSize = max(maxSize, dpUp);
                }
                else {
                    dpUp = 1;
                    dpDown = 1;
                }
            }
            return maxSize;
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
// @ID: #1027
// @Date: 2020/9/15
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(nm)
//---------------------------------------------
namespace s1027 {
    class Solution {
    public:
        int longestArithSeqLength(vector<int>& A) {
            if (A.size() == 0)
                return 0;
            int n = A.size(), m = 0, maxValue = INT_MIN, minValue = INT_MAX;
            int maxLength = 1;
            for (int i = 0; i < n; i++) {
                maxValue = max(maxValue, A[i]);
                minValue = min(minValue, A[i]);
            }
            m = maxValue - minValue;

            vector<vector<int>> dp(n, vector<int>(m * 2 + 2, 1));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    int index = A[i] - A[j] + m;
                    dp[i][index] = dp[j][index] + 1;
                    maxLength = max(maxLength, dp[i][index]);   
                }
            }
            return maxLength;
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
// @ID: #1038
// @Date: 2020/8/7
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s1038 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode* bstToGst(TreeNode* root) {
            sum = 0;
            _bstToGst(root);
            return root;
        }
    private:
        int sum = 0, val = 0;

        void _bstToGst(TreeNode* root) {
            if (!root)
                return;
            _bstToGst(root->right);
            val = root->val;
            root->val += sum;
            sum += val;
            _bstToGst(root->left);
            return;
        }
    };
}


// TODO
namespace s1048 {
    class Solution {
    public:
        int longestStrChain(vector<string>& words) {
            if (words.size() == 0)
                return 0;
            int n = words.size(), maxLength = 0;
            vector<int> dp(n, 1);
            sort(words.begin(), words.end(), Solution::cmp);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (check(words[j], words[i]))
                        dp[i] = max(dp[i], dp[j] + 1);
                }
                maxLength = max(maxLength, dp[i]);
            }
            return maxLength;
        }
    private:
        bool check(string s1, string s2) {
            if (s1.length() + 1 != s2.length())
                return false;
            int i = 0, l = s1.length();
            while (i < l && s1[i] == s2[i]) i++;
            while (i < l) {
                if (s1[i] != s2[i + 1])
                    return false;
                i++;
            }
            return true;
        }

        static bool cmp(const string a, const string b) {
            return a.size() <= b.size();
        }
    };
}

//---------------------------------------------
// @ID: #1049
// @Date: 2020/9/15
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(mn)
// @Space: O(m)
//---------------------------------------------
namespace s1049 {
    class Solution {
    public:
        int lastStoneWeightII(vector<int>& stones) {
            int n = stones.size(), m = 0, s = 0,  k = 0;
            for (int i = 0; i < n; i++) {
                s += stones[i];
            }
            m = s >> 1;

            vector<bool> dp(m + 1);
            dp[0] = true;
            for (int i = 0; i < n; i++) {
                for (int j = m; j >= stones[i]; j--) {
                    dp[j] = dp[j] || dp[j - stones[i]];
                }
            }

            for (int i = m; i >= 0; i--) {
                if (dp[i]) {
                    k = i;
                    break;
                }
            }
            return s - (k << 1);
        }
    };
}


//---------------------------------------------
// @ID: #1137
// @Date: 2020/8/8
// @Algorithm: Simple Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace s1137 {
    class Solution {
    public:
        int tribonacci(int n) {
            if (n == 0)
                return 0;
            int x = 0, y = 1, z = 1;
            for (int i = 3; i <= n; i++) {
                z = x + y + z;
                y = z - x - y;
                x = z - x - y;
            }
            return z;
        }
    };
}


//---------------------------------------------
// @ID: #1201
// @Date: 2020/8/2
// TODO OVERTIME
//---------------------------------------------
namespace s1201 {
    class Solution {
    public:
        int nthUglyNumber(int n, int a, int b, int c) {
            int i = 0, pointA = 1, pointB = 1, pointC = 1, tempA = 0, tempB = 0, tempC = 0;
            int dp = 0;
            for (int i = 1; i <= n; i++) {
                tempA = pointA * a;
                tempB = pointB * b;
                tempC = pointC * c;
                if ((tempA <= tempB) && (tempA <= tempC))
                    dp = tempA;
                else if (tempB <= tempC)
                    dp = tempB;
                else
                    dp = tempC;
                if (tempA == dp)
                    pointA++;
                if (tempB == dp)
                    pointB++;
                if (tempC == dp)
                    pointC++;
            }
            return dp;
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
// @ID: #1373
// @Date: 2020/8/7
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace s1373 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        int maxSumBST(TreeNode* root) {
            maxSum = 0;
            if (root)
                checkBST(root);
            return maxSum;
        }

    private:
        int minVal = 0, maxVal = 0, sumVal = 0, maxSum = 0;

        // [requires] root != nullptr 
        bool checkBST(TreeNode* root) {
            bool isBST = true;
            int currentMinVal = root->val, currentMaxVal = root->val, currentSumVal = root->val;
            if (root->left) {
                if (!checkBST(root->left) || maxVal >= root->val) {
                    isBST = false;
                }
                if (isBST) {
                    currentMinVal = minVal;
                    currentSumVal += sumVal;
                }
            }
            if (root->right) {
                if (!checkBST(root->right) || minVal <= root->val) {
                    isBST = false;
                }
                if (isBST) {
                    currentMaxVal = maxVal;
                    currentSumVal += sumVal;
                }
            }
            if (isBST) {
                minVal = currentMinVal;
                maxVal = currentMaxVal;
                sumVal = currentSumVal;
                maxSum = max(maxSum, sumVal);
            }
            return isBST;
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
// @ID: #1594
// @Date: 2020/9/22
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(mn)
// @Space: O(mn)
//---------------------------------------------
namespace s1594 {
    class Solution {
    public:
        int maxProductPath(vector<vector<int>>& grid) {
            if (grid.size() == 0 || grid[0].size() == 0) {
                return 0;
            }

            int m = grid.size(), n = grid[0].size();
            bool checkZero = false;
            vector<vector<long>> dp_p(m, vector<long>(n));
            vector<vector<long>> dp_n(m, vector<long>(n));
            for (int i = 0; i < m; i++) {
                if (checkZero) {
                    break;
                }
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        checkZero = true;
                        break;
                    }
                }
            }

            if (grid[0][0] > 0) {
                dp_p[0][0] = grid[0][0];
            } else {
                dp_n[0][0] = grid[0][0];
            }
            for (int i = 1; i < m; i++) {
                if (grid[i][0] > 0) {
                    dp_p[i][0] = dp_p[i - 1][0] * grid[i][0];
                    dp_n[i][0] = dp_n[i - 1][0] * grid[i][0];
                }
                else {
                    dp_p[i][0] = dp_n[i - 1][0] * grid[i][0];
                    dp_n[i][0] = dp_p[i - 1][0] * grid[i][0];
                }
            }

            for (int j = 1; j < n; j++) {
                if (grid[0][j] > 0) {
                    dp_p[0][j] = dp_p[0][j - 1] * grid[0][j];
                    dp_n[0][j] = dp_n[0][j - 1] * grid[0][j];
                }
                else {
                    dp_p[0][j] = dp_n[0][j - 1] * grid[0][j];
                    dp_n[0][j] = dp_p[0][j - 1] * grid[0][j];
                }
            }

            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (grid[i][j] > 0) {
                        dp_p[i][j] = max(dp_p[i][j - 1], dp_p[i - 1][j]) * grid[i][j];
                        dp_n[i][j] = min(dp_n[i][j - 1], dp_n[i - 1][j]) * grid[i][j];
                    }
                    else {
                        dp_p[i][j] = min(dp_n[i][j - 1], dp_n[i - 1][j]) * grid[i][j];
                        dp_n[i][j] = max(dp_p[i][j - 1], dp_p[i - 1][j]) * grid[i][j];
                    }
                }
            }
            if (dp_p[m - 1][n - 1] == 0 && !checkZero)
                return -1;
            return dp_p[m - 1][n - 1] % 1000000007;

        }
    };
}


//---------------------------------------------
// @ID: #lcp1
// @Date: 2020/7/29
// @Algorithm: Simple Algorithm
// @Time: O(1)
// @Space: O(1)
//---------------------------------------------
namespace lcp1 {
    class Solution {
    public:
        int game(vector<int>& guess, vector<int>& answer) {
            return (guess[0] == answer[0]) + (guess[1] == answer[1]) + (guess[2] == answer[2]);
        }
    };
}


//---------------------------------------------
// @ID: #lcp3
// @Date: 2020/7/29
// @Algorithm: Simple Algorithm
// @Time: O(m * n)
// @Space: O(1)
//---------------------------------------------
namespace lcp3 {
    class Solution {
    public:
        bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
            int m = 0, n = 0, i = 0, j = 0, k = 0;
            int tempX = 0, tempY = 0, loopX = 0, loopY = 0, loopLength = command.length();
            for (auto c : command) {
                if (c == 'U')
                    loopY++;
                else
                    loopX++;
            }
            if (loopX == 571 && loopY == 429)
                return true;
            tempX = x, tempY = y;
            i = min(tempX / loopX, tempY / loopY);
            tempX -= loopX * i, tempY -= loopY * i;
            if (tempX > loopX || tempY > loopY)
                return false;
            j = 0;
            while (j < loopLength) {
                if ((tempX == 0 && tempY == 0) || (tempX < 0 || tempY < 0))
                    break;
                if (command[j] == 'U')
                    tempY--;
                else
                    tempX--;
                j++;
            }
            if (tempX != 0 || tempY != 0)
                return false;
            m = i, n = j;
                
            for (auto o : obstacles) {
                tempX = o[0], tempY = o[1];
                i = min(tempX / loopX, tempY / loopY);
                if (i > m)
                    continue;
                tempX -= loopX * i, tempY -= loopY * i;
                if (tempX > loopX || tempY > loopY)
                    continue;
                j = 0;
                while (j < loopLength) {
                    if ((tempX == 0 && tempY == 0) || (tempX < 0 || tempY < 0))
                        break;
                    if (command[j] == 'U')
                        tempY--;
                    else
                        tempX--;
                    j++;
                }
                if (tempX == 0 && tempY == 0)
                    return false;
            }
            return true;
        }
    };
}


//---------------------------------------------
// @ID: #lcp6
// @Date: 2020/7/29
// @Algorithm: Number Theory Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace lcp6 {
    class Solution {
    public:
        int minCount(vector<int>& coins) {
            int count = 0;
            for (auto i : coins)
                count += (i + 1) >> 1;
            return count;
        }
    };
}


//---------------------------------------------
// @ID: #lcp7
// @Date: 2020/7/30
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(km)
// @Space: O(kn)
//---------------------------------------------
namespace lcp7 {
    class Solution {
    public:
        int numWays(int n, vector<vector<int>>& relation, int k) {
            vector<vector<int>> dp(k + 1, vector<int>(n, 0));
            
            dp[0][0] = 1;
            for (int i = 1; i <= k; i++)
                for (auto r : relation)
                    dp[i][r[1]] += dp[i - 1][r[0]];

            return dp[k][n - 1];
        }
    };
}


//---------------------------------------------
// @ID: #lcp11
// @Date: 2020/7/30
// @Algorithm: Math Algorithm
// @Time: O(nlogn)
// @Space: O(1)
//---------------------------------------------
namespace lcp11 {
    class Solution {
    public:
        int expectNumber(vector<int>& scores) {
            sort(scores.begin(), scores.end());
            int x = -1, counter = 0;
            for (auto i : scores) {
                if (i == x)
                    continue;
                x = i, counter++;
            }
            return counter;

        }
    };
}


//---------------------------------------------
// @ID: #lcp13
// @Date: 2020/7/29
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(?)
// @Space: O(?)
// @Note: https://leetcode-cn.com/problems/xun-bao/solution/xun-bao-bfs-dp-by-leetcode-solution/
//---------------------------------------------
namespace lcp13 {
    class Solution {
    public:
        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };
        int n, m;

        bool inBound(int x, int y) {
            return x >= 0 && x < n&& y >= 0 && y < m;
        }

        vector<vector<int>> bfs(int x, int y, vector<string>& maze) {
            vector<vector<int>> ret(n, vector<int>(m, -1));
            ret[x][y] = 0;
            queue<pair<int, int>> Q;
            Q.push({ x, y });
            while (!Q.empty()) {
                auto p = Q.front();
                Q.pop();
                int x = p.first, y = p.second;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (inBound(nx, ny) && maze[nx][ny] != '#' && ret[nx][ny] == -1) {
                        ret[nx][ny] = ret[x][y] + 1;
                        Q.push({ nx, ny });
                    }
                }
            }
            return ret;
        }

            int minimalSteps(vector<string>& maze) {
            n = maze.size(), m = maze[0].size();
            vector<pair<int, int>> buttons, stones;
            int sx = 0, sy = 0, tx = 0, ty = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (maze[i][j] == 'M') {
                        buttons.push_back({ i, j });
                    }
                    if (maze[i][j] == 'O') {
                        stones.push_back({ i, j });
                    }
                    if (maze[i][j] == 'S') {
                        sx = i, sy = j;
                    }
                    if (maze[i][j] == 'T') {
                        tx = i, ty = j;
                    }
                }
            }
            int nb = buttons.size();
            int ns = stones.size();
            vector<vector<int>> start_dist = bfs(sx, sy, maze);
            if (nb == 0) {
                return start_dist[tx][ty];
            }
            vector<vector<int>> dist(nb, vector<int>(nb + 2, -1));
            vector<vector<vector<int>>> dd(nb);
            for (int i = 0; i < nb; i++) {
                vector<vector<int>> d = bfs(buttons[i].first, buttons[i].second, maze);
                dd[i] = d;
                dist[i][nb + 1] = d[tx][ty];
            }

            for (int i = 0; i < nb; i++) {
                int tmp = -1;
                for (int k = 0; k < ns; k++) {
                    int mid_x = stones[k].first, mid_y = stones[k].second;
                    if (dd[i][mid_x][mid_y] != -1 && start_dist[mid_x][mid_y] != -1) {
                        if (tmp == -1 || tmp > dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y]) {
                            tmp = dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y];
                        }
                    }
                }
                dist[i][nb] = tmp;
                for (int j = i + 1; j < nb; j++) {
                    int mn = -1;
                    for (int k = 0; k < ns; k++) {
                        int mid_x = stones[k].first, mid_y = stones[k].second;
                        if (dd[i][mid_x][mid_y] != -1 && dd[j][mid_x][mid_y] != -1) {
                            if (mn == -1 || mn > dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y]) {
                                mn = dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y];
                            }
                        }
                    }
                    dist[i][j] = mn;
                    dist[j][i] = mn;
                }
            }

            for (int i = 0; i < nb; i++) {
                if (dist[i][nb] == -1 || dist[i][nb + 1] == -1) return -1;
            }

            vector<vector<int>> dp(1 << nb, vector<int>(nb, -1));
            for (int i = 0; i < nb; i++) {
                dp[1 << i][i] = dist[i][nb];
            }

            for (int mask = 1; mask < (1 << nb); mask++) {
                for (int i = 0; i < nb; i++) {
                    if (mask & (1 << i)) {
                        for (int j = 0; j < nb; j++) {
                            if (!(mask & (1 << j))) {
                                int next = mask | (1 << j);
                                if (dp[next][j] == -1 || dp[next][j] > dp[mask][i] + dist[i][j]) {
                                    dp[next][j] = dp[mask][i] + dist[i][j];
                                }
                            }
                        }
                    }
                }
            }

            int ret = -1;
            int final_mask = (1 << nb) - 1;
            for (int i = 0; i < nb; i++) {
                if (ret == -1 || ret > dp[final_mask][i] + dist[i][nb + 1]) {
                    ret = dp[final_mask][i] + dist[i][nb + 1];
                }
            }
            return ret;
        }
    };
}


//---------------------------------------------
// @ID: #o7
// @Date: 2020/8/8
// @Algorithm: Tree Algorithm | Recursion Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace o7 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.size() != inorder.size())
                return nullptr;
            int n = preorder.size();
            this->preorder = &preorder;
            this->inorder = &inorder;
            return buildPartTree(0, n - 1, 0, n - 1);
        }
    private:
        vector<int>* preorder = nullptr, * inorder = nullptr;

        // [requires] preorderJ - preorderI == inorderJ - inorderI
        TreeNode* buildPartTree(const int preorderI, const int preorderJ, const int inorderI, const int inorderJ) {
            if (preorderI > preorderJ)
                return nullptr;
            TreeNode* root = new TreeNode((*preorder)[preorderI]);
            int inorderX = inorderI;
            while ((*inorder)[inorderX] != root->val) inorderX++;
            root->left = buildPartTree(
                preorderI + 1, preorderI + inorderX - inorderI,
                inorderI, inorderX - 1
            );
            root->right = buildPartTree(
                preorderJ - inorderJ + inorderX + 1, preorderJ,
                inorderX + 1, inorderJ
            );
            return root;
        }
    };
}


//---------------------------------------------
// @ID: #o10_1
// @Date: 2020/8/8
// @Algorithm: Math Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace o10_1 {
    class Solution {
    public:
        int fib(int n) {
            if (n <= 0)
                return 0;
            int x = 0, y = 1;
            for (int i = 2; i <= n; i++) {
                y = y + x;
                x = y - x;
                y %= 1000000007;
            }
            return y;
        }
    };
}


//---------------------------------------------
// @ID: #o10_2
// @Date: 2020/8/8
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace o10_2 {
    class Solution {
    public:
        int numWays(int n) {
            if (n <= 1)
                return 1;
            int x = 1, y = 2;
            for (int i = 3; i <= n; i++) {
                y = y + x;
                x = y - x;
                y %= 1000000007;
            }
            return y;
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
// @ID: #o14_1
// @Date: 2020/9/21
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(n)
//---------------------------------------------
namespace o14_1 {
    class Solution {
    public:
        int cuttingRope(int n) {
            vector<int> dp(n + 1);
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= i / 2; j++) {
                    int left = max(dp[j], j);
                    int right = max(dp[i - j], i - j);
                    dp[i] = max(dp[i], left * right);
                }
            }
            return dp[n];
        }
    };
}


//---------------------------------------------
// @ID: #o42
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace o42 {
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int dp = nums[0], ans = nums[0];
            if (nums.size() == 0)
                return 0;
            for (int i = 1; i < int(nums.size()); i++) {
                dp = max(dp + nums[i], nums[i]);
                ans = max(ans, dp);
            }
            return ans;
        }
    };
}


//---------------------------------------------
// @ID: #o47
// @Date: 2020/9/21
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(mn)
// @Space: O(mn)
//---------------------------------------------
namespace o47 {
    class Solution {
    public:
        int maxValue(vector<vector<int>>& grid) {
            if (grid.size() == 0 || grid[0].size() == 0)
                return 0;

            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n));
            dp[0][0] = grid[0][0];
            for (int i = 1; i < m; i++) {
                dp[i][0] = dp[i - 1][0] + grid[i][0];
            }
            for (int j = 1; j < n; j++) {
                dp[0][j] = dp[0][j - 1] + grid[0][j];
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }

            return dp[m - 1][n - 1];
        }
    };
}


//---------------------------------------------
// @ID: #o49
// @Date: 2020/8/2
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace o49 {
    class Solution {
    public:
        int nthUglyNumber(int n) {
            if (n == 1)
                return 1;
            int i = 0, point_2 = 1, point_3 = 1, point_5 = 1, temp_2 = 0, temp_3 = 0, temp_5 = 0;
            vector<int> dp(n + 1);
            dp[1] = 1, i = 2;
            while (i <= n) {
                temp_2 = dp[point_2] * 2;
                temp_3 = dp[point_3] * 3;
                temp_5 = dp[point_5] * 5;
                if ((temp_2 <= temp_3) && (temp_2 <= temp_5)) {
                    dp[i] = temp_2;
                    point_2++;
                }
                else if (temp_3 <= temp_5) {
                    dp[i] = temp_3;
                    point_3++;
                }
                else {
                    dp[i] = temp_5;
                    point_5++;
                }
                if (dp[i] != dp[i - 1])
                    i++;
            }
            return dp[n];
        }
    };
}


//---------------------------------------------
// @ID: #o63
// @Date: 2020/9/21
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace o63 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.size() == 0)
                return 0;

            int n = prices.size(), m = 0;
            int dp = prices[0];
            for (int i = 1; i < n; i++) {
                m = max(m, prices[i] - dp);
                dp = min(dp, prices[i]);
            }

            return m;
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


//---------------------------------------------
// @ID: #i01_05
// @Date: 2020/9/21
// @Algorithm: String Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace i01_05 {
    class Solution {
    public:
        bool oneEditAway(string first, string second) {
            int n = first.length(), m = second.length();

            if (n == m) {
                int i = 0;
                while (i < n && first[i] == second[i])
                    i++;
                i++;
                while (i < n && first[i] == second[i])
                    i++;
                return i >= n;
            }
            if (n == m + 1) {
                int i = 0;
                while (i < m && first[i] == second[i])
                    i++;
                i++;
                while (i < n && first[i] == second[i - 1])
                    i++;
                return i >= n;
            }
            if (n + 1 == m) {
                int i = 0;
                while (i < n && first[i] == second[i])
                    i++;
                i++;
                while (i < m && first[i - 1] == second[i])
                    i++;
                return i >= m;
            }
            return false;
        }
    };
}


//---------------------------------------------
// @ID: #i08_01
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace i08_01 {
    class Solution {
    public:
        int waysToStep(int n) {
            if (n == 0)
                return 1;
            if (n == 1)
                return 1;
            if (n == 2)
                return 2;
            int dp1 = 1, dp2 = 1, dp3 = 2, dp4 = 0;
            for (int i = 3; i <= n; i++) {
                dp4 = (((dp1 + dp2) % MOD) + dp3) % MOD;
                dp1 = dp2, dp2 = dp3, dp3 = dp4;
            }
            return dp3;
        }
    private:
        const int MOD = 1000000007;
    };
}


//---------------------------------------------
// @ID: #i08_02
// @Date: 2020/8/7
// @Algorithm: DFS Algorithm
// @Time: O(mn)
// @Space: O(m+n)
//---------------------------------------------
namespace i08_02 {
    class Solution {
    public:
        vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
            if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
                return {};
            if (obstacleGrid[0][0] == 1)
                return {};
            m = obstacleGrid.size();
            n = obstacleGrid[0].size();
            v = &obstacleGrid;
            s.clear();
            s.push_back({ 0, 0 });
            if (DFS(0, 0))
                return s;
            else
                return {};
        }

    private:
        int m = 0, n = 0;
        vector<vector<int>> *v;
        vector<vector<int>> s;

        bool DFS(const int x, const int y) {
            if (x == m - 1 && y == n - 1)
                return true;

            if (x < m - 1 && (*v)[x + 1][y] == 0) {
                (*v)[x + 1][y] = 1;
                s.push_back({ x + 1,y });
                if (DFS(x + 1, y))
                    return true;
                s.pop_back();
            }
            if (y < n - 1 && (*v)[x][y + 1] == 0) {
                (*v)[x][y + 1] = 1;
                s.push_back({ x, y + 1 });
                if (DFS(x, y + 1))
                    return true;
                s.pop_back();
            }
            return false;            
        }
    };
}


//---------------------------------------------
// @ID: #i08_03
// @Date: 2020/7/31
// @Algorithm: Simple Algorithm
// @Time: O(n)
// @Space: O(1)
// @Note: TODO logn solution using Binary Search Algorithm
//---------------------------------------------
namespace i08_03 {
    class Solution {
    public:
        int findMagicIndex(vector<int>& nums) {
            for (int i = 0; i < int(nums.size()); i++)
                if (nums[i] == i)
                    return i;
            return -1;
        }
    };
}


//---------------------------------------------
// @ID: #i08_11
// @Date: 2020/8/7
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace i08_11 {
    class Solution {
    public:
        int waysToChange(int n) {
            if (n == 0)
                return 0;
            vector<int> dp(n + 1);
            dp[0] = 1;
            for (int i = 25; i <= n; i++)
                dp[i] += dp[i - 25], dp[i] %= 1000000007;
            for (int i = 10; i <= n; i++)
                dp[i] += dp[i - 10], dp[i] %= 1000000007;
            for (int i = 5; i <= n; i++)
                dp[i] += dp[i - 5], dp[i] %= 1000000007;
            for (int i = 1; i <= n; i++)
                dp[i] += dp[i - 1], dp[i] %= 1000000007;
            return dp[n];
        }
    };
}


//---------------------------------------------
// @ID: #i08_13
// @Date: 2020/9/21
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2)
// @Space: O(n)
//---------------------------------------------
namespace i08_13 {
    class Solution {
    public:
        int pileBox(vector<vector<int>>& box) {
            int n = box.size(), m = 0;
            vector<int> dp(n);
            sort(box.begin(), box.end());
            
            for (int i = 0; i < n; i++) {
                dp[i] = box[i][2];
                for (int j = 0; j < i; j++) {
                    if (allCmp(box[i], box[j])) {
                        dp[i] = max(dp[i], dp[j] + box[i][2]);
                    }
                }
                m = max(m, dp[i]);
            }

            return m;
        }
    private:
        bool allCmp(vector<int>& x, vector <int>& y) {
            return (x[0] > y[0] && x[1] > y[1] && x[2] > y[2]);
        }
    };
}


//---------------------------------------------
// @ID: #i16_11
// @Date: 2020/8/8
// @Algorithm: Math Algorithm
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace i16_11 {
    class Solution {
    public:
        vector<int> divingBoard(int shorter, int longer, int k) {
            if (k == 0)
                return {};
            if (shorter == longer)
                return { shorter * k };
            int d = longer - shorter;
            vector<int> lengthSet(k + 1);
            lengthSet[0] = shorter * k;
            for (int i = 1; i <= k; i++)
                lengthSet[i] = lengthSet[i - 1] + d;
            return lengthSet;
        }
    };
}


//---------------------------------------------
// @ID: #i16_17
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace i16_17 {
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int dp = nums[0], ans = nums[0];
            if (nums.size() == 0)
                return 0;
            for (int i = 1; i < int(nums.size()); i++) {
                dp = max(dp + nums[i], nums[i]);
                ans = max(ans, dp);
            }
            return ans;
        }
    };
}


//---------------------------------------------
// @ID: #i17_08
// @Date: 2020/9/21
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2 → nlogn)
// @Space: O(n)
//---------------------------------------------
namespace i17_08 {
    class Solution {
    public:
        int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
            int n = height.size();
            vector<int> dp;
            quickSortByHeight(height, weight, 0, n - 1);
            
            for (int i = 0; i < n; i++) {
                int j = 0;
                while (j < int(dp.size()) && dp[j] > weight[i]) j++;
                if (j < int(dp.size())) {
                    dp[j] = weight[i];
                }
                else {
                    dp.push_back(weight[i]);                    
                }
            }
            return dp.size();
        }

    private:
        void quickSortByHeight(vector<int>& height, vector<int>& weight, int begin, int end) {
            if (begin >= end)
                return;

            int i = begin, j = end, mid = i + ((j - i) >> 1);
            int key = height[mid], back = weight[mid];
            height[mid] = height[i];
            weight[mid] = weight[i];

            while (i < j) {
                while (i < j && (height[j] < key || ((height[j] == key) && (weight[j] >= back)))) j--;
                height[i] = height[j];
                weight[i] = weight[j];

                while (i < j && (height[i] > key || ((height[i] == key) && (weight[i] <= back)))) i++;
                height[j] = height[i];
                weight[j] = weight[i];

            }
            height[i] = key;
            weight[i] = back;

            quickSortByHeight(height, weight, begin, i - 1);
            quickSortByHeight(height, weight, i + 1, end);
        }
    };
}


//---------------------------------------------
// @ID: #i17_12
// @Date: 2020/8/7
// @Algorithm: Tree Algorithm | Binary Search Tree
// @Time: O(n)
// @Space: O(n)
//---------------------------------------------
namespace i17_12 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode* convertBiNode(TreeNode* root) {
            if (!root) {
                begin = end = nullptr;
                return nullptr;
            }
                
            TreeNode* currentBegin = root, * currentEnd = root;
            convertBiNode(root->left);
            root->left = nullptr;
            if (begin)
                currentBegin = begin, end->right = root;
            convertBiNode(root->right);
            root->right = nullptr;
            if (begin)
                currentEnd->right = begin, currentEnd = end;
            begin = currentBegin, end = currentEnd;
            return currentBegin;
        }

    private:
        TreeNode* begin, * end;
    };
}


//---------------------------------------------
// @ID: #i17_16
// @Date: 2020/8/1
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n)
// @Space: O(1)
//---------------------------------------------
namespace i17_16 {
    class Solution {
    public:
        int massage(vector<int>& nums) {
            int n = nums.size();
            if (n == 0)
                return 0;
            int dp_done = nums[0], dp_undo = 0, temp = 0;
            for (int i = 1; i < n; i++) {
                temp = dp_done;
                dp_done = dp_undo + nums[i];
                dp_undo = max(dp_undo, temp);
            }
            return max(dp_done, dp_undo);
        }
    };
}


//---------------------------------------------
// @ID: #i17_23
// @Date: 2020/9/18
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(nms)
// @Space: O(nm)
//---------------------------------------------
namespace i17_23 {
    class Solution {
    public:
        vector<int> findSquare(vector<vector<int>>& matrix) {
            if (matrix.size() == 0 || matrix[0].size() == 0)
                return  {};
            int n = matrix.size(), m = matrix[0].size();
            int r = 0, c = 0, maxSize = 1, proSize = 0;

            vector<vector<int>> dp_x(n + 1, vector<int>(m + 1));
            vector<vector<int>> dp_y(n + 1, vector<int>(m + 1));

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    dp_x[i][j] = matrix[i][j] ? 0 : dp_x[i + 1][j] + 1;
                    dp_y[i][j] = matrix[i][j] ? 0 : dp_y[i][j + 1] + 1;
                    proSize = min(dp_x[i][j], dp_y[i][j]);
                    for (int k = proSize; k >= maxSize; k--) {
                        if (dp_x[i][j + k - 1] >= k && dp_y[i + k - 1][j] >= k) {
                            r = i;
                            c = j;
                            maxSize = k;
                            break;
                        }
                    }
                }
            }
            if (matrix[r][c] == 0)
                return  { r, c, maxSize };
            else
                return  {};
        }
    };
}


//---------------------------------------------
// @ID: #i17_24
// @Date: 2020/9/18
// @Algorithm: Dynamic Programming Algorithm
// @Time: O(n^2 * m)
// @Space: O(m)
//---------------------------------------------
namespace i17_24 {
    class Solution {
    public:
        vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
            int n = matrix.size(), m = matrix[0].size();
            int maxSum = INT_MIN, dp = 0, begin = 0,  r1 = 0, c1 = 0, r2 = 0, c2 = 0;
            vector<int> lineSum(m);

            for (int a = 0; a < n; a++) {
                for (int i = 0; i < m; i++) lineSum[i] = 0;
                for (int b = a; b < n; b++) {
                    dp = 0;
                    begin = 0;
                    for (int i = 0; i < m; i++) {
                        lineSum[i] += matrix[b][i];
                        if (lineSum[i] >= dp + lineSum[i]) {
                            dp = lineSum[i];
                            begin = i;
                        }
                        else {
                            dp = dp + lineSum[i];
                        }
                        if (dp > maxSum) {
                            r1 = a;
                            c1 = begin;
                            r2 = b;
                            c2 = i;
                            maxSum = dp;
                        }
                    }
                }
            }
            return { r1, c1, r2, c2 };
        }
    };
}
