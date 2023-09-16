/*
problem:- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
TreeNode* solve(vector<int>& pre,int mini,int maxi,int &i)
{
    int n=pre.size();
    if(i>=n)
    {
        return NULL;
    }

    if(pre[i]<mini || pre[i]>maxi)
    {
        return NULL;
    }
    TreeNode* root=new TreeNode(pre[i++]);
    root->left=solve(pre,mini,root->val,i);
    root->right=solve(pre,root->val,maxi,i);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return solve(preorder,mini,maxi,i);
    }
};