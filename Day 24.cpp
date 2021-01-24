// Day 24
// Question : Merge k Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(a==NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        ListNode* res;
        if(a->val<=b->val)
        {
            res=a;
            res->next=merge(a->next,b);
        }
        else
        {
            res=b;
            res->next=merge(a,b->next);
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
        {
            return NULL;
        }
        if(n==1)
        {
            return lists[0];
        }
        for(int i=1;i<n;i++)
        {
            lists[0]=merge(lists[0],lists[i]);
        }
        return lists[0];
    }
};
