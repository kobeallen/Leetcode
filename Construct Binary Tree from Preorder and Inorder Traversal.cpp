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
    vector<int> preOrder;
    vector<int> inOrder;
    TreeNode *DFS(int pos, int left, int right)
    {
        if(left > right)
            return NULL;
        int val = preOrder[pos];
        int split;
        TreeNode *now = new TreeNode(val);
        if(left == right)
            return now;
        for(int i = left; i <= right; ++i)
        {
            if(inOrder[i] == val)
            {
                split = i;
                break;
            }
        }
        int leftSize = split - left;
        now->left = DFS(pos + 1, left, split - 1);
        now->right = DFS(pos + leftSize + 1, split + 1, right);
        return now;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        preOrder.clear();
        inOrder.clear();
        for(int i = 0; i < preorder.size(); ++i)
            preOrder.push_back(preorder[i]);
        for(int i = 0; i < inorder.size(); ++i)
            inOrder.push_back(inorder[i]);
        TreeNode *root = DFS(0, 0, inOrder.size() - 1);
        return root;
    }
};