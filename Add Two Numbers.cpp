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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *t1=new ListNode(0);
        ListNode *t2=new ListNode(0);
        ListNode *ans=new ListNode(0);
        ListNode *t=new ListNode(0);
        t1=l1, t2=l2, t=ans;
        int result, digit=0;
        result=digit;
        if(t1!=NULL)
        {
            result+=t1->val;
            t1=t1->next;
        }
        if(t2!=NULL)
        {
            result+=t2->val;
            t2=t2->next;
        }
        digit=result/10;
        t->val=result%10;
        while(t1!=NULL||t2!=NULL)
        {
            ListNode *nt=new ListNode(0);
            t->next=nt;
            t=t->next;
            result=digit;
            if(t1!=NULL)
            {
                result+=t1->val;
                t1=t1->next;
            }
            if(t2!=NULL)
            {
                result+=t2->val;
                t2=t2->next;
            }
            digit=result/10;
            t->val=result%10;
        }
        if(digit>0)
        {
            ListNode *nt=new ListNode(digit);
            t->next=nt;
            t=t->next;
        }
        return ans;
    }
};
