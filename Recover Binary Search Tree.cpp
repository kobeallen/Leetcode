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
    void DFS(TreeNode *now, vector<TreeNode *> &ans)
    {
        if(now == NULL)
            return ;
        DFS(now->left, ans);
        ans.push_back(now);
        DFS(now->right, ans);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return ;
        vector<TreeNode *> ans;
        DFS(root, ans);
        TreeNode *left = new TreeNode(0);
        TreeNode *right = new TreeNode(0);
        for(int i = 0; i < ans.size() - 1; ++i)
        {
            if(ans[i]->val > ans[i+1]->val)
            {
                left = ans[i];
                break;
            }            
        }                               
        for(int i = ans.size() - 1; i > 0; --i)
        {
            if(ans[i]->val < ans[i-1]->val)
            {
                right = ans[i];
                break;
            }            
        }        
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
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
    void DFS(TreeNode *now, TreeNode **previous, TreeNode **first, TreeNode **second)
    {
        if(now == NULL)
            return ;
        DFS(now->left, previous, first, second);
        if(*previous != NULL)
        {
            if((*previous)->val > now->val)
            {
                if(*first == NULL)
                {
                    *first = *previous;
                    *second = now;
                }
                else
                    *second = now;
            }
        }
        *previous = now;
        DFS(now->right, previous, first, second);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        TreeNode *previous = NULL;
        DFS(root, &previous, &first, &second);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
};