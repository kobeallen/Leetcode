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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ans=new ListNode(0);
        ListNode *t=new ListNode(0);
        t=ans;
        int i, size=lists.size();
        int result, id;
        vector<ListNode *> t_list;
        result=1000000;
        for(i=0;i<size;i++)
        {
            t_list.push_back(lists[i]);
            if(lists[i]!=NULL&&lists[i]->val<result)
            {
                result=lists[i]->val;
                id=i;
            }
        }
        if(result==1000000)
            return NULL;
        t->val=lists[id]->val;
        t_list[id]=t_list[id]->next;
        while(1)
        {
            result=1000000;
            for(i=0;i<size;i++)
            {
                if(t_list[i]!=NULL&&t_list[i]->val<result)
                {
                    result=t_list[i]->val;
                    id=i;
                }
            }
            if(result==1000000)
                break;
            ListNode *nt=new ListNode(result);
            t->next=nt;
            t=t->next;
            t_list[id]=t_list[id]->next;
        }
        return ans;
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(lists.empty())
            return NULL;
        int id;
        ListNode *max = NULL;
        for(int i = 0; i < lists.size(); ++i)
        {
            if(lists[i] != NULL)
            {
                if(max == NULL || max->val > lists[i]->val)
                {
                    max = lists[i];
                    id = i;
                }                
            }
        }
        if(max == NULL)
            return NULL;
        ListNode *ans = new ListNode(max->val);
        ListNode *now = ans;
        lists[id] = lists[id]->next;
        while(1)
        {
            max = NULL;
            for(int i = 0; i < lists.size(); ++i)
            {
                if(lists[i] != NULL)
                {
                    if(max == NULL || max->val > lists[i]->val)
                    {
                        max =lists[i];
                        id = i;
                    }
                }
            }
            if(max == NULL)
                break;
            ListNode *next = new ListNode(max->val);
            now->next = next;
            now = next;
            lists[id] = lists[id]->next;
        }
        return ans;
    }
};