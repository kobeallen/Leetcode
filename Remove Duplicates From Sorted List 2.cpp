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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;
        ListNode *i = current->next;
        while(i != NULL)
        {
            int count = 0;
            ListNode *next = i->next;
            while(next != NULL && next->val == i->val)
            {
                ++count;
                next = next->next;
            }
            if(count == 0)
            {
                current->next = i;
                current = current->next;
            }
            i = next;
        }
        current->next = NULL;
        return dummy->next;
    }
};