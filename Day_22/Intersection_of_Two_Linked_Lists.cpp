/*
problem:- https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL or headB==NULL)
        {
            return NULL;
        }
        while (headB) {
        ListNode* temp = headA;
        while (temp) {
        
            if (temp == headB)
                return headB;
            temp = temp->next;
        }
        headB = headB->next;
    }
    return NULL; 
    }
};