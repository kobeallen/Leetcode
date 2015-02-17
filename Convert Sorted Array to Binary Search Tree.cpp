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
    TreeNode *DFS(vector<int> num, int left, int right)
    {       
        if(left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *now = new TreeNode(num[mid]);        
        if(left <= mid - 1)
            now->left = DFS(num, left, mid - 1);
        if(mid + 1 <= right)
            now->right = DFS(num, mid + 1, right);
        return now;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *root = new TreeNode(0);        
        root = DFS(num, 0, num.size() - 1);
        return root;
    }
};
