class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		if(head==NULL)
			return head;
		ListNode *t=new ListNode(0);
		t=head;
		int i, length=0;
		while(t!=NULL)
		{
			length++;
			t=t->next;
		}
		if(length==n)
		{
			head=head->next;
			return head;
		}
		t=head;
		for(i=1;i<length-n;i++)
		{
			t=t->next;
		}
		t->next=t->next->next;
		return head;
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *left = head;
        ListNode *right = head;
        ListNode *previous = NULL;
        for(int i = 1; i < n; ++i)
        {
            right = right->next;
        }
        while(right->next != NULL)
        {
            previous = left;
            left = left->next;
            right =right->next;
        }
        if(previous == NULL)
            return head->next;
        else
        {
            previous->next = left->next;
            return head;
        }
    }
};