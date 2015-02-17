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
    bool DFS(TreeNode *left, TreeNode *right)
    {
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL || right == NULL)
            return false;
        if(left->val != right->val)
            return false;
        bool L = DFS(left->left, right->right);
        bool R = DFS(left->right, right->left);
        if(L == false || R == false)
            return false;
        else
            return true;
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        else
            return DFS(root->left, root->right);
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
    bool DFS(TreeNode *left, TreeNode *right)
    {
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL || right == NULL)
            return false;
        if(left->val != right->val)
            return false;
        bool a = DFS(left->left, right->right);
        bool b = DFS(left->right, right->left);
        if(a == true && b == true)
            return true;
        return false;
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        return DFS(root->left, root->right);
    }
};