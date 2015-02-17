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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(-100000);
        dummy->next = head;
        ListNode *now = head->next;
        ListNode *previous = head;
        ListNode *i;
        while(now != NULL)
        {
            i = dummy;
            while(i != previous && i->next->val < now->val)
                i = i->next;
            if(i == previous)
            {
                previous = now;
                now = now->next;
            }
            else
            {
                previous->next = now->next;
                now->next = i->next;
                i->next = now;
                now = previous->next;
            }
        }
        return dummy->next;
    }
};
