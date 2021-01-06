// Day 5
// Question : Remove Duplicates from Sorted List II

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        set<int> s;
        while(temp!=NULL&&temp->next!=NULL)
        {
            if(temp->val==temp->next->val)
            {
                ListNode* nex=temp->next->next;
                s.insert(temp->val);
                temp->next=nex;
            }
            else
            {
                temp=temp->next;
            }
        }
        temp=head;
        ListNode* pre=NULL;
        while(temp!=NULL)
        {
            if(s.find(temp->val)!=s.end())
            {
                if(pre==NULL)
                {
                    temp=temp->next;
                    head=head->next;
                }
                else
                {
                    pre->next=temp->next;
                    temp=temp->next;
                }
            }
            else
            {
                pre=temp;
                temp=temp->next;
            }
        }
        return head;

    }
};
