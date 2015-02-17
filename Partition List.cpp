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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL)
            return NULL;
        ListNode *root=new ListNode(0);
        ListNode *t=new ListNode(0);
        ListNode *i=new ListNode(0);
        t=root;
        bool first=true;
        i=head;
        while(i!=NULL)
        {
            if(i->val<x)
            {
                if(first==true)
                {
                    t->val=i->val;
                    first=false;
                }
                else
                {
                    ListNode *nt=new ListNode(i->val);
                    t->next=nt;
                    t=t->next;
                }
            }
            i=i->next;
        }
        i=head;
        while(i!=NULL)
        {
            if(i->val>=x)
            {
                if(first==true)
                {
                    t->val=i->val;
                    first=false;
                }
                else
                {
                    ListNode *nt=new ListNode(i->val);
                    t->next=nt;
                    t=t->next;
                }
            }
            i=i->next;
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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return NULL;
        int length = 0;
        ListNode *t = head;
        ListNode *tail;
        while(t != NULL)
        {
            ++length;
            tail = t;
            t = t->next;
        }        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        t = dummyHead;
        while(length > 0)
        {
            if(t->next->val < x)
            {
                --length;
                t = t->next;
            }
            else
            {
                --length;
                ListNode *next = new ListNode(t->next->val);
                tail->next = next;
                tail = next;
                t->next = t->next->next;
            }
        }
        return dummyHead->next;
    }
};