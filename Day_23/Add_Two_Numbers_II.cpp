/*
problem:- https://leetcode.com/problems/add-two-numbers-ii/
*/

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
    void insertAtTail(ListNode * &head,ListNode * &tail,int data)
    {
        ListNode * temp=new ListNode(data);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    ListNode *Reverse(ListNode* l1)
    {
        //base case
	    if(l1==NULL or l1->next==NULL)
	    {
		    return l1;
	    }
	     //otherwise
	    ListNode *shead=Reverse(l1->next);
	    l1->next->next=l1;
	    l1->next=NULL;
	    return shead;
    }
    ListNode *Add(ListNode* l1, ListNode* l2)
    {
        int carry=0;
        ListNode *ansHead=NULL;
        ListNode *ansTail=NULL;
        while(l1!=NULL or l2!=NULL or carry!=0)
        {
            int val1=0;
            int val2=0;
            if(l1!=NULL)
            {
                val1=l1->val;
            }
            if(l2!=NULL)
            {
                val2=l2->val;
            }
            int sum=carry+val1+val2;
            int digit=sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
             if(l1!=NULL)
            {
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                l2=l2->next;
            }
        }
        
        return ansHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=Reverse(l1);
        l2=Reverse(l2);
        ListNode * ans=Add(l1,l2);
        ans=Reverse(ans);
        return ans;
        
    }
};