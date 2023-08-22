/*
problem:- https://leetcode.com/problems/sum-of-left-leaves/
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
    private:
    void SumLeaf(TreeNode* root,int &sum,bool &flag)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL && flag)
        {
            sum+=root->val;
        }
        flag=true;
        SumLeaf(root->left,sum,flag);
        flag=false;
        SumLeaf(root->right,sum,flag);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        bool flag=false;
        SumLeaf(root,sum,flag);
        return sum;
    }
};