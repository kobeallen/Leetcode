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
    ListNode *Sort(ListNode *now, int left, int right)
    {
        if(left == right)
            return now;
        int mid = (left + right) / 2;
        ListNode *head1 = now;
        ListNode *tail1 = now;
        ListNode *head2;
        ListNode *tail2;
        for(int i = left; i < mid; ++i)
            tail1 = tail1->next;
        head2 = tail1->next;
        tail1->next = NULL;
        tail2 = head2;
        for(int i = mid + 1; i < right; ++i)
            tail2 = tail2->next;
        tail2->next = NULL;
        head1 = Sort(head1, left, mid);
        head2 = Sort(head2, mid + 1, right);
        ListNode *head;
        if(head1->val < head2->val)
        {
            head = head1;
            head1 = head1->next;
        }
        else
        {
            head = head2;
            head2 = head2->next;
        }
        ListNode *current = head;
        while(head1 != NULL || head2 != NULL)
        {
            if(head2 == NULL || (head1 != NULL && head1->val < head2->val))
            {
                current->next = head1;
                current = current->next;
                head1 = head1->next;
            }
            else
            {
                current->next = head2;
                current = current->next;
                head2 = head2->next;
            }
        }
        return head;
    }
    
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)
            return NULL;
        ListNode *now = head;
        int size = 0;
        while(now != NULL)
        {
            ++size;
            now = now->next;
        }
        head = Sort(head, 0, size - 1);
        return head;
    }
};
