/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
            return NULL;
        RandomListNode *now = head;
        RandomListNode *tmp;
        while(now != NULL)
        {
            RandomListNode *next = new RandomListNode(now->label);
            tmp = now->next;
            now->next = next;
            next->next = tmp;
            now = tmp;
        }
        now = head;
        while(now != NULL)
        {
            now->next->random = now->random == NULL ? NULL : now->random->next;
            now = now->next->next;
        }
        RandomListNode *copyHead = head->next;
        now = head;
        while(now != NULL)
        {
            tmp = now->next;
            now->next = now->next->next;
            tmp->next = now->next == NULL ? NULL : now->next->next;
            now = now->next;
        }
        return copyHead;
    }
};
