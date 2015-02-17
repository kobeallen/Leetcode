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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(NULL);
        TreeNode *now = new TreeNode(0);
        while(!Q.empty())
        {
            vector<int> result;
            now = Q.front();
            Q.pop();
            if(now == NULL)
                break;
            while(now != NULL)
            {
                if(now->left != NULL)
                    Q.push(now->left);
                if(now->right != NULL)
                    Q.push(now->right);
                result.push_back(now->val);
                now = Q.front();
                Q.pop();
            }
            Q.push(NULL);
            ans.push_back(result);
        }
        return ans;
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> result;
        if(root == NULL)
            return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);
        while(1)
        {
            result.clear();
            while(1)
            {
                TreeNode *now = Q.front();
                Q.pop();
                if(now == NULL)
                    break;
                result.push_back(now->val);
                if(now->left != NULL)
                    Q.push(now->left);
                if(now->right != NULL)
                    Q.push(now->right);
            }
            ans.push_back(result);
            if(Q.empty())
                break;
            Q.push(NULL);
        }
        return ans;
    }
};