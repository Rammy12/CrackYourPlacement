/*
problem:- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
TreeNode* solve(vector<int>&in,vector<int>&post,int &index,int instart,int inend,unordered_map<int,int>&nodeindex)
{
    if(index<0 || instart > inend)
    {
        return NULL;
    }
    int element=post[index--];
    TreeNode* root=new TreeNode(element);
    //int pos=findpos(in,element);
    int pos=nodeindex[element];

    //root->left=solve(in,post,index,instart,pos-1,nodeindex);
    root->right=solve(in,post,index,pos+1,inend,nodeindex);
    root->left=solve(in,post,index,instart,pos-1,nodeindex);
    return root;
}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex=postorder.size()-1;
        unordered_map<int,int>nodeindex;
        createmap(inorder,nodeindex);
        TreeNode* ans=solve(inorder,postorder,postindex,0,postorder.size()-1,nodeindex);
        return ans;
    }
};