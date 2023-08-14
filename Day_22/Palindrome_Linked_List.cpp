/*
problem:- https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast!=NULL) {
            slow = slow->next;
            fast = fast->next;
            if (!fast)
            {
                break;
            }
            fast = fast->next;
        }
        
        ListNode *prev = NULL, *curr = slow;
        while (curr!=NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
      
        while (prev) {
            if (prev->val != head->val)
            {
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};