/*
problem:- https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
int getLength(ListNode* head)
{
    int n=0;
    while(head!=NULL)
    {
        n++;
        head=head->next;
    }
    return n;
}
    int getDecimalValue(ListNode* head) {
        ListNode* curr=head;
        int n=getLength(head);
        int ans=0;
        while(curr!=NULL)
        {
            int value=curr->val;
            ans+=pow(2,n-1)*value;
            n--;
            curr=curr->next;
        }
        return ans;
    }
};