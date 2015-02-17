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
    bool DFS(TreeNode *now, int sum, int targetSum)
    {
        sum += now->val;
        if(now->left == NULL && now->right == NULL)
        {
            if(sum == targetSum)
                return true;
            else
                return false;
        }
        if(now->left != NULL)
        {
            if(DFS(now->left, sum, targetSum) == true)
                return true;
        }
        if(now->right != NULL)
        {
            if(DFS(now->right, sum, targetSum) == true)
                return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return false;
        return DFS(root, 0, sum);
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
    bool DFS(TreeNode *now, int sum)
    {
        if(now->left == NULL && now->right == NULL)
        {
            if(sum - now->val == 0)
                return true;
            else
                return false;
        }
        if(now->left != NULL)
        {
            if(DFS(now->left, sum - now->val))
                return true;
        }
        if(now->right != NULL)
        {
            if(DFS(now->right, sum - now->val))
                return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return false;
        return DFS(root, sum);
    }
};