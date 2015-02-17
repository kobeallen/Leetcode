/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *DFS(ListNode **head, int left, int right)
    {
        if(left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *now = new TreeNode(0);
        if(left <= mid - 1)
            now->left = DFS(head, left, mid - 1);
        now->val = (*head)->val;
        (*head) = (*head)->next;
        if(mid + 1 <= right)
            now->right = DFS(head, mid + 1, right);                
        return now;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        ListNode *t = new ListNode(0);
        t = head;
        int length = 0;
        while(t != NULL)
        {
            ++length;
            t = t->next;            
        }
        if(length == 0)
            return NULL;
        else
        {
            TreeNode *root = new TreeNode(0);
            root = DFS(&head, 1, length);
            return root;
        }
    }
};
