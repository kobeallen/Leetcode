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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack<TreeNode*> S;
        TreeNode *previous = NULL;
        TreeNode *current;
        S.push(root);
        while(!S.empty())
        {
            current = S.top();
            if(previous == NULL || previous->left == current || previous->right == current)
            {
                if(current->left != NULL)
                    S.push(current->left);
                else if(current->right != NULL)
                    S.push(current->right);
                else
                {
                    ans.push_back(current->val);
                    S.pop();
                }
            }
            else if(current->left == previous)
            {
                if(current->right != NULL)
                    S.push(current->right);
                else
                {
                    ans.push_back(current->val);
                    S.pop();
                }
            }
            else if(current->right == previous)
            {
                ans.push_back(current->val);
                S.pop();
            }
            previous = current;
        }
        return ans;
    }
};
