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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<TreeNode*> S;
        TreeNode *now;
        vector<int> ans;
        if(root == NULL)
            return ans;
        S.push(root);
        while(!S.empty())
        {
            now = S.top();
            S.pop();
            ans.push_back(now->val);
            if(now->right != NULL)
                S.push(now->right);
            if(now->left != NULL)
                S.push(now->left);
        }
        return ans;
    }
};
