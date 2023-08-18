/*
problem:- https://leetcode.com/problems/merge-in-between-linked-lists/
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list1;
        for(int i = 0; i < a-1; i++)
        {
            l1 = l1 -> next;
        }
        for(int i = 0; i < b; i++)
        {
            l2=l2->next;
        } 
        ListNode* temp = l2 -> next;
        l1 -> next = list2;
        ListNode* l3 = list2;
        while(l3 -> next != NULL)
        {
            l3 = l3 -> next;
        }
        l3 -> next = temp;
        return list1;
    }
};