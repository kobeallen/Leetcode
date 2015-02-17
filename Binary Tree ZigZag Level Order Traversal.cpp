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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;
        stack<TreeNode *> Q[2];
        int now = 0, next = 1;
        Q[0].push(root);        
        TreeNode *current = new TreeNode(0);        
        bool left = true;
        while(1)
        {
            vector<int> result;
            if(Q[now].empty())
                break;                
            while(!Q[now].empty())
            {
                current = Q[now].top();
                Q[now].pop();
                result.push_back(current->val);
                if(left == true)
                {
                    if(current->left != NULL)
                        Q[next].push(current->left);
                    if(current->right != NULL)
                        Q[next].push(current->right);                    
                }
                else
                {
                    if(current->right != NULL)
                        Q[next].push(current->right);
                    if(current->left != NULL)
                        Q[next].push(current->left);                    
                }            
            }            
            if(left == true)
                left = false;
            else
                left = true;
            ans.push_back(result);
            now = (now + 1) % 2;
            next = (next + 1) % 2;
        }
        return ans;
    }
};