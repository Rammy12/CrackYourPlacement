/*
problem:- https://leetcode.com/problems/balanced-binary-tree/
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
/*private:
int height(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}*/
private:
pair<bool,int>isbalancedFast(TreeNode* root)
{
    if(root==NULL)
    {
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    pair<bool,int>Left=isbalancedFast(root->left);
    pair<bool,int>Right=isbalancedFast(root->right);
    bool leftpart=Left.first;
    bool rightpart=Right.first;
    bool diff=abs(Left.second-Right.second)<=1;
    pair<bool,int>ans;
    ans.second=max(Left.second,Right.second)+1;
    if(leftpart && rightpart && diff)
    {
        ans.first=true;
    }
    else
    {
        ans.first=false;
    }
    return ans;
}
public:
    bool isBalanced(TreeNode* root) {
        /*if(root==NULL)
        {
            return true;
        }*/
        /*bool leftpart=isBalanced(root->left);
        bool rightpart=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        if(leftpart && rightpart && diff)
        {
            return true;
        }
        else
        {
            return false;
        }
        time complexity O(n^2)
        */
        pair<bool,int>ans=isbalancedFast(root);
        return ans.first;

    }
};