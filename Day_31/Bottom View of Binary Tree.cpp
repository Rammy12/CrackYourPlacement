/*
problem:- https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
*/
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<pair<Node *,int> >q;
        map<int,int>m;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node *,int> temp=q.front();
            q.pop();
            Node * frontNode=temp.first;
            int hrd=temp.second;
            
            m[hrd]=frontNode->data;
            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left,hrd-1));
            }
            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right,hrd+1));
            }
        }
        for(auto x:m)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};