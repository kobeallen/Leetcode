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
    void Reverse(ListNode **start, ListNode **end)
    {        
        ListNode *t1=new ListNode(0);
        ListNode *t2=new ListNode(0);
        t1=(*start);
        t2=(*start)->next;        
        while(t1!=(*end))
        {
            ListNode *nt=new ListNode(0);
            nt=t2->next;
            t2->next=t1;
            t1=t2;
            t2=nt;            
        }
    }
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL)
            return NULL;
        int i;
        ListNode *root=new ListNode(0);
        ListNode *start=new ListNode(0);
        ListNode *end=new ListNode(0);
        start=head, end=head;
        for(i=1;i<k;i++)
        {
            if(end==NULL)
                break;
            end=end->next;
        }
        if(end==NULL)
            return head;
        root=end;
        while(1)
        {
            ListNode *t1=new ListNode(0);
            ListNode *t2=new ListNode(0);
            t1=end->next;
            t2=t1;
            Reverse(&start, &end);            
            for(i=1;i<k;i++)
            {
                if(t2==NULL)
                    break;
                t2=t2->next;
            }
            if(t2==NULL)
            {
                start->next=t1;
                break;
            }
            else
            {
                start->next=t2;
                start=t1;
                end=t2;
            }            
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k <= 1)
            return head;
        ListNode *left = head;
        ListNode *right = head;
        ListNode *previous = NULL;
        for(int i = 0; i < k - 1 && right != NULL; ++i)
        {            
            right = right->next;
        }
        while(left != NULL && right != NULL)
        {
            if(previous == NULL)
            {
                head = right;
            }    
            else
            {
                previous->next = right;
            }
            previous = left;            
            ListNode *now = left;
            ListNode *next = left->next;            
            left->next = right->next; 
            for(int i = 0; i < k - 1; ++i)
            {
                ListNode *tmp = next->next;
                next->next = now;
                now = next;
                next = tmp;
            }
            left = left->next;
            right = left;
            for(int i = 0; i < k - 1 && right != NULL; ++i)
                right = right->next;
        }
        return head;
    }
};
