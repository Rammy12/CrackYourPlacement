/*
problem:- https://leetcode.com/problems/balance-a-binary-search-tree/
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
TreeNode* BuildBST(int s,int e,vector<int>&v)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=s+(e-s)/2;
    TreeNode* root=new TreeNode(v[mid]);
    root->left=BuildBST(s,mid-1,v);
    root->right=BuildBST(mid+1,e,v);
    return root;
}
void inorder(TreeNode* root,vector<int>&v)
{
    //base case
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);//L
    v.push_back(root->val); //N
    inorder(root->right,v);  //R
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int n=v.size();
        return BuildBST(0,n-1,v);
    }
};