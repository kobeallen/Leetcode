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
    void DFS(TreeNode *now, int result, int &ans)
    {           
        result = 10 * result + now->val;
        if(now->left == NULL && now->right == NULL)
        {
            ans += result;
            return ;
        }
        if(now->left != NULL)
            DFS(now->left, result, ans);
        if(now->right != NULL)
            DFS(now->right, result, ans);        
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        int result = 0, ans = 0;
        DFS(root, result, ans);
        return ans;
    }
};
