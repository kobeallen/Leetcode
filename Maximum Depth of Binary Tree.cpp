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
        if(now == NULL)
            return 0;
        if(now->left == NULL && now->right == NULL)
            return 1;
        int left = DFS(now->left);
        int right = DFS(now->right);
        return left > right ? left + 1 : right + 1;
    }
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        int left = 0, right = 0;
        if(root->left != NULL)
            left = maxDepth(root->left);
        if(root->right != NULL)
            right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
};
