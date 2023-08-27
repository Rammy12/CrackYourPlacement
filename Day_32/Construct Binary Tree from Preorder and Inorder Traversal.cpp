/*
problem:- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
void createmap(vector<int>in,unordered_map<int,int>&nodeindex)
{
    for(int i=0; i<in.size(); i++)
    {
        nodeindex[in[i]]=i;
    }
}
TreeNode* solve(vector<int>&pre,vector<int>&in,int &index,int instart,int inend,unordered_map<int,int>&nodeindex)
{
    if(index>=pre.size() || instart > inend)
    {
        return NULL;
    }
    int element=pre[index++];
    TreeNode* root=new TreeNode(element);
    //int pos=findpos(in,element);
    int pos=nodeindex[element];

    root->left=solve(pre,in,index,instart,pos-1,nodeindex);
    root->right=solve(pre,in,index,pos+1,inend,nodeindex);
    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inorderindex=0;
        unordered_map<int,int>nodeindex;
        createmap(inorder,nodeindex);
        TreeNode* ans=solve(preorder,inorder,inorderindex,0,preorder.size()-1,nodeindex);
        return ans;
    }
};