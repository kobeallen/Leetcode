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
    void DFS(TreeNode *now, vector<int> &ans)
    {
        if(now == NULL)
            return ;
        DFS(now->left, ans);
        ans.push_back(now->val);
        DFS(now->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        DFS(root, ans);
        return ans;
    }
};
