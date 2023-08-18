/*
problem:- https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)
        {
            return NULL;
        } 
        if(!head->next)
        {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        for(int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
        }
        ListNode *curr = prev->next;
        for(int i = 0; i < right - left; i++)
        {
            ListNode *temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy->next;
    }
};