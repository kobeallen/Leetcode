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
    bool DFS(TreeNode *p, TreeNode *q)
    {
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL)
            return false;        
        if(p->val != q->val)
            return false;
        bool left = DFS(p->left, q->left);
        bool right = DFS(p->right, q->right);
        if(left == false || right == false)
            return false;
        else
            return true;
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return DFS(p, q);
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        if(p->val != q->val)
            return false;
        bool a = isSameTree(p->left, q->left);
        bool b = isSameTree(p->right, q->right);
        if(a == true && b == true)
            return true;
        return false;
    }
};