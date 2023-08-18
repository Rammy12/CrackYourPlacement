/*
problem:- https://leetcode.com/problems/remove-nodes-from-linked-list/
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
    ListNode* removeNodes(ListNode* head) {
        vector<int>vec;
        ListNode* curr=head,*temp=NULL;
        while(curr!=NULL)
        {
            vec.push_back(curr->val);
            curr=curr->next;
        }
        stack<pair<int,int>>st;
        for(int i=vec.size()-1; i>=0; i--)
        {
            if(st.empty())
            {
                st.push({vec[i],1});
            }
            else
            {
                if(st.top().first>vec[i])
                {
                    st.push({st.top().first,-1});
                }
                else
                {
                    st.push({vec[i],1});
                }
            }
        }
        curr=head;
        while(!st.empty())
        {
            if(st.top().second==1)
            {
                curr->val=st.top().first;
                temp=curr;
                curr=curr->next;
            }
            st.pop();
        }
        temp->next=NULL;
        return head;
    }
};