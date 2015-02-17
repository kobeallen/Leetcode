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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL)
            return NULL;
        int length=0;
        ListNode *t=new ListNode(0);
        t=head;
        while(t!=NULL)
        {
            length++;
            t=t->next;
        }
        k=k%length;
        ListNode *start=new ListNode(0);
        ListNode *end=new ListNode(0);
        start=head, end=head;
        while(end->next!=NULL)
            end=end->next;
        end->next=start;
        for(int i=1;i<length-k;i++)
            start=start->next;
        ListNode *root=new ListNode(0);
        root=start->next;
        start->next=NULL;
        return root;
    }
};