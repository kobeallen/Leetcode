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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)
            return ;
        vector<ListNode *> LL;
        ListNode *now = head;
        while(now != NULL)
        {
            LL.push_back(now);
            now = now->next;
        }
        int left = 0, right = LL.size() - 1;
        while(left + 1 < right)
        {
            LL[right-1]->next = NULL;
            LL[right]->next = LL[left]->next;
            LL[left]->next = LL[right];
            ++left;
            --right;
        }
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
    ListNode* Reverse(ListNode *head)
    {
        if(head == NULL)
            return NULL;
        ListNode *now = head;
        ListNode *next = now->next;
        ListNode *tmp;
        now->next = NULL;
        while(next != NULL)
        {
            tmp = next->next;
            next->next = now;
            now = next;
            next = tmp;
        }
        return now;
    }
    
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)
            return ;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;
        head2 = Reverse(head2);
        ListNode *now1 = head;
        ListNode *now2 = head2;
        ListNode *tmp1;
        ListNode *tmp2;
        while(now1 != NULL && now2 != NULL)
        {
            tmp1 = now1->next;
            tmp2 = now2->next;
            now2->next = tmp1;
            now1->next = now2;
            now1 = tmp1;
            now2 = tmp2;
        }
    }
};
