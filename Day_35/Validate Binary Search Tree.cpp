/*
problem:- https://leetcode.com/problems/validate-binary-search-tree/
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
/*
bool solve(TreeNode* root,int min,int max)
{
    //base case
    if(root==NULL)
    {
        return true;
    }
    if(root->val>=min and root->val <= max)
    {
        bool Left=solve(root->left,min,root->val);
        bool Right=solve(root->right,root->val,max);
        return Left & Right;
    }
    return false;
}
*/

void inorder(TreeNode* root,vector<int>&v)
{
    //base case
    if(root==NULL)
    {
        return ;
    }
    //LNR
    inorder(root->left,v);  //L
    v.push_back(root->val); //N
    inorder(root->right,v);  //R
}
    bool isValidBST(TreeNode* root) {
        // Approch #1 using inorder
        vector<int>v;
        inorder(root,v);
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] <= v[i - 1]) {
                return false;
            }
        }
        return true;
        // Approch #2 
        //return solve(root,INT_MIN,INT_MAX);
    }
};