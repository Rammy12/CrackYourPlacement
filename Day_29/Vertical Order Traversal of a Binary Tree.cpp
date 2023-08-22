/*
problem:- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,vector<int> > > node;
        queue<pair<TreeNode*,pair<int,int> > >q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int> > temp=q.front();
            q.pop();
            TreeNode* curr=temp.first;
            int hrd=temp.second.first;
            int vrd=temp.second.second;
            node[hrd][vrd].push_back(curr->val);
            if(curr->left)
            {
                q.push(make_pair(curr->left,make_pair(hrd-1,vrd+1)));
            }
            if(curr->right)
            {
                q.push(make_pair(curr->right,make_pair(hrd+1,vrd+1)));
            }
        }
        for(auto &it: node){
            vector<int> curr;
            for(auto &i: it.second){
                sort(i.second.begin(),i.second.end());
                for(int j=0;j<i.second.size();j++){
                    curr.push_back(i.second[j]);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};