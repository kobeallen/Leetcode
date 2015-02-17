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
    vector<TreeNode *> DFS(int left, int right)
    {
        vector<TreeNode *> ans;
        vector<TreeNode *> LChild;
        vector<TreeNode *> RChild;
        if(left > right)
        {
            ans.push_back(NULL);
            return ans;
        }        
        for(int i = left; i <= right; ++i)
        {
            LChild = DFS(left, i - 1);
            RChild = DFS(i + 1, right);
            for(int j = 0; j < LChild.size(); ++j)
            {
                for(int k = 0; k < RChild.size(); ++k)
                {
                    TreeNode *now = new TreeNode(i);
                    now->left = LChild[j];
                    now->right = RChild[k];
                    ans.push_back(now);
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return DFS(1, n);
    }
};