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
    vector<int> inOrder;
    vector<int> postOrder;
    TreeNode *DFS(int pos, int left, int right)
    {
        if(left > right)
            return NULL;
        int val = postOrder[pos];
        TreeNode *now = new TreeNode(val);
        if(left == right)
            return now;
        int split;
        for(int i = right; i >= left; --i)
        {
            if(inOrder[i] == val)
            {
                split = i;
                break;
            }
        }
        int rightSize = right - split;
        now->left = DFS(pos - rightSize - 1, left, split - 1);
        now->right =DFS(pos - 1, split + 1, right);
        return now;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        inOrder.clear();
        postOrder.clear();
        for(int i = 0; i < inorder.size(); ++i)
            inOrder.push_back(inorder[i]);
        for(int i = 0; i < postorder.size(); ++i)
            postOrder.push_back(postorder[i]);
        TreeNode *root = DFS(postOrder.size() - 1, 0, inOrder.size() - 1);
        return root;
    }
};