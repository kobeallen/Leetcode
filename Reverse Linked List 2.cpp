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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *start = head;
        ListNode *previous = NULL;
        for(int i = 1; i < m; ++i)
        {
            previous = start;
            start = start->next;
        }
        ListNode *end = head;
        for(int i = 1; i < n; ++i)
            end = end->next;
        ListNode *t1 = start;
        ListNode *t2 = start->next;
        ListNode *t3;
        start->next = end->next;
        while(t1 != end)
        {
            t3 = t2->next;
            t2->next = t1;
            t1 = t2;
            t2 = t3;
        }
        if(previous != NULL)
        {
            previous->next = end;
            return head;
        }
        else
            return end;
    }
};