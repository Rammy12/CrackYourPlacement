/*
problem:- https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 0, i = 1;
        while (temp) {
            temp = temp -> next;
            length++;
        }
        if (length == n) {
            return head -> next;  
        }        
        for (temp = head; i < length - n; i++) {
            temp = temp -> next; 
        }
        temp -> next = temp -> next -> next;     
        return head;

    }
};