/*
problem:- https://www.codingninjas.com/studio/problems/merge-two-bsts_920474
*/

/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
vector<int> Merge_vector(vector<int>a,vector<int>b)
{
    vector<int>ans(a.size()+b.size());
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]>b[j])
        {
            ans[k++]=b[j];
            j++;
        }
        else
        {
            ans[k++]=a[i];
            i++;
        }
    }
    while(i<a.size())
    {
        ans[k++]=a[i];
        i++;
    }
    while(j<b.size())
    {
        ans[k++]=b[j];
        j++;
    }
    return ans;
}
void inorder(TreeNode *root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int>bst1,bst2,merged_vector;
    inorder(root1,bst1);
    inorder(root2,bst2);
    merged_vector=Merge_vector(bst1,bst2);
    return merged_vector;
}