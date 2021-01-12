// Day 12
// Question : Add Two Numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        ListNode* res=NULL;
        ListNode* pre=NULL;
        int carry=0;
        while(l1!=NULL&&l2!=NULL)
        {
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            if(res==NULL)
            {
                res=temp;
                pre=temp;
            }
            else
            {
                pre->next=temp;
                pre=pre->next;
            }

            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int sum=l1->val+carry;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            pre->next=temp;
            pre=pre->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int sum=l2->val+carry;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            pre->next=temp;
            pre=pre->next;
            l2=l2->next;
        }
        if(carry)
        {
            ListNode* temp=new ListNode(carry);
            pre->next=temp;
            pre=pre->next;
        }
        pre->next=NULL;
        return res;
    }
};
