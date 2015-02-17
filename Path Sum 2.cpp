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
    void DFS(TreeNode *now, int sum, int targetSum, vector<int> result, vector<vector<int> > &ans)
    {
        sum += now->val;
        result.push_back(now->val);
        if(now->left == NULL && now->right == NULL)
        {
            if(sum == targetSum)
                ans.push_back(result);
            return ;
        }
        if(now->left != NULL)
        {
            DFS(now->left, sum, targetSum, result, ans);    
        }
        if(now->right != NULL)
        {
            DFS(now->right, sum, targetSum, result, ans);
        }
        return ;
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> result;
        if(root == NULL)
            return ans;
        DFS(root, 0, sum, result, ans);
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
    void DFS(TreeNode *now, int sum, vector<int> &result, vector<vector<int> > &ans)
    {
        if(now->left == NULL && now->right == NULL)
        {
            if(sum - now->val == 0)
            {
                result.push_back(now->val);
                ans.push_back(result);
                result.pop_back();
                return ;
            }
        }
        result.push_back(now->val);
        if(now->left != NULL)
        {            
            DFS(now->left, sum - now->val, result, ans);            
        }
        if(now->right != NULL)
        {
            DFS(now->right, sum - now->val, result, ans);
        }
        result.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> result;
        if(root == NULL)
            return ans;
        DFS(root, sum, result, ans);
        return ans;
    }
};