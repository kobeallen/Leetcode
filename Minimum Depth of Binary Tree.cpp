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
    int DFS(TreeNode *now)
    {
        if(now->left == NULL && now->right == NULL)
            return 1;
        int ans = 10000, result;
        if(now->left != NULL)
        {
            result = DFS(now->left);
            if(result < ans)
                ans = result;
        }
        if(now->right != NULL)
        {
            result = DFS(now->right);
            if(result < ans)
                ans = result;
        }
        return ans + 1;
    }
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        return DFS(root);
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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        int left = 10000, right = 10000;
        if(root->left != NULL)
            left = minDepth(root->left);
        if(root->right != NULL)
            right = minDepth(root->right);
        return left < right ? left + 1 : right + 1;
    }
};
