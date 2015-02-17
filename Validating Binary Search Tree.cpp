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
    void DFS(TreeNode *now, vector<int> &result)
    {
        if(now == NULL)
            return ;        
        DFS(now->left, result);
        result.push_back(now->val);        
        DFS(now->right, result);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        DFS(root, result);
        int i;
        for(i = 1; i < result.size(); ++i)
        {
            if(result[i - 1] >= result[i])
                break;
        }
        if(i < result.size())
            return false;
        else
            return true;
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
    void DFS(TreeNode *now, TreeNode **previous, bool &ans)
    {
        if(now == NULL)
            return ;
        DFS(now->left, previous, ans);
        if(*previous != NULL)
        {
            if((*previous)->val >= now->val)
                ans = false;
        }
        *previous = now;
        DFS(now->right, previous, ans);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *previous = NULL;
        bool ans = true;
        DFS(root, &previous, ans);
        return ans;
    }
};