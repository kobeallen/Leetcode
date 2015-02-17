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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *t1=new ListNode(0);
        ListNode *t2=new ListNode(0);
        ListNode *ans=new ListNode(0);
        ListNode *t=new ListNode(0);
        t1=l1, t2=l2, t=ans;
        if(t1->val<t2->val)
        {
            t->val=t1->val;
            t1=t1->next;
        }
        else
        {
            t->val=t2->val;
            t2=t2->next;
        }
        while(t1!=NULL||t2!=NULL)
        {
            ListNode *nt=new ListNode(0);
            t->next=nt;
            t=t->next;
            if(t1==NULL)
            {
                nt->val=t2->val;
                t2=t2->next;
            }
            else if(t2==NULL)
            {
                nt->val=t1->val;
                t1=t1->next;
            }
            else if(t1->val<t2->val)
            {
                nt->val=t1->val;
                t1=t1->next;
            }
            else
            {
                nt->val=t2->val;
                t2=t2->next;
            }
        }
        return ans;
    }
};
