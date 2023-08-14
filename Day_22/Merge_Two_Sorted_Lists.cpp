/*
problem:- https://leetcode.com/problems/merge-two-sorted-lists/
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
ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode* curr1=list1;
    ListNode* curr2=list2;
    ListNode* next1=list1->next;
    ListNode* next2=list2->next;
    if(list1->next==NULL)
    {
        list1->next=list2;
        return list1;
    }
    while(next1!=NULL and curr2!=NULL)
    {
        if(curr2->val>=curr1->val and next1->val>=curr2->val)
        {
            //add number
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            //update pointer
            curr1=curr2;
            curr2=next2;
        }
        else
        {
            curr1=next1;
            next1=next1->next;
            if(next1==NULL)
            {
                curr1->next=curr2;
                return list1;
            }
        }
    }
    return list1;
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        if(list1->val<=list2->val)
        {
            return merge(list1,list2);
        }
        else
        {
            return merge(list2,list1);
        }
    }
};