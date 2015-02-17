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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return ;
        flatten(root->left);
        flatten(root->right);
        if(root->left != NULL)
        {
            TreeNode *now = root->left;
            while(now->right != NULL)
                now = now->right;
            now->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
