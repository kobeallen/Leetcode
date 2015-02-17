/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)    return NULL;
        ListNode *current = head;
        for(ListNode *i = current->next; i != NULL; i = i->next)
        {
            if(current->val != i->val)
            {
                current = current->next;
                current->val = i->val;
            }
        }
        current->next = NULL;
        return head;
    }
};