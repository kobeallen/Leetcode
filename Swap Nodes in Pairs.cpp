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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        ListNode *root=new ListNode(0);
        ListNode *first=new ListNode(0);
        ListNode *second=new ListNode(0);
        first=head, second=head->next;
        root=head->next;
        while(first!=NULL&&second!=NULL)
        {
            ListNode *t=new ListNode(0);
            t=second->next;
            second->next=first;
            if(t==NULL)
            {
                first->next=NULL;
                second=NULL;
            }
            else if(t->next==NULL)
            {
                first->next=t;
                second=NULL;
            }
            else
            {
                first->next=t->next;
                second=t->next;
            }
            first=t;
        }
        return root;
    }
};

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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *left = head;
        ListNode *right = head->next;
        ListNode *previous = NULL;
        while(left != NULL && right != NULL)
        {
            left->next = right->next;
            right->next = left;
            if(previous != NULL)
            {
                previous->next = right;
            }
            else
            {
                head = right;
            }
            previous = left;
            left = left->next;
            if(left != NULL)
            {
                right = left->next;
            }
        }
        return head;
    }
};
