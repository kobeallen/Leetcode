/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int MaxPathRoot(TreeNode *now, int &max)
    {
        if(now == NULL)
            return 0;
        int left, right, result = now->val;
        left = MaxPathRoot(now->left, max);
        right = MaxPathRoot(now->right, max);
        if(left >= 0)
            result += left;
        if(right >= 0)
            result += right;
        if(max < result)
            max = result;
        int ans = left > right ? left : right;
        if(ans >= 0)
            return ans + now->val;
        else
            return now->val;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = -1000000;
        int rootAns = MaxPathRoot(root, ans);
        return ans;
    }
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int DFS(TreeNode *now, int &ans)
    {
        int result = now->val, left_sum = 0, right_sum = 0, sum = now->val, tmp;
        if(now->left != NULL)
            left_sum = DFS(now->left, ans);
        if(now->right != NULL)
            right_sum = DFS(now->right, ans);
        if(left_sum < right_sum)
            tmp = right_sum;
        else
            tmp = left_sum;
        if(tmp > 0)
            result += tmp;
        if(left_sum > 0)
            sum += left_sum;
        if(right_sum > 0)
            sum += right_sum;
        if(ans < sum)
            ans = sum;
        return result;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = -1000000;
        int result = DFS(root, ans);
        return ans;
    }
};
