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
        int left = DFS(now->left);
        int right = DFS(now->right);
        if(left == -1 || right == -1)
            return -1;
        if(abs(left - right) >= 2)
            return -1;
        return left > right ? left + 1 : right + 1;
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = DFS(root);
        if(ans == -1)
            return false;
        else
            return true;
    }
};
