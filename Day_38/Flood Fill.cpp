/*
problem:- https://leetcode.com/problems/flood-fill/description/
*/

class Solution {
public:
bool isValid(int i,int j,int n,int m,vector<vector<int>>& image,int val)
{
    if(i>=0 && i<n && j>=0 && j<m && image[i][j]==val)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(int i,int j,int color,vector<vector<int>>& image)
{
    int n=image.size();
    int m=image[0].size();
    int val=image[i][j];
    if (val == color) {
        return;
    }
    image[i][j]=color;
    if(isValid(i-1,j,n,m,image,val))
    {
        solve(i-1,j,color,image);
    }
    if(isValid(i+1,j,n,m,image,val))
    {
        solve(i+1,j,color,image);
    }
    if(isValid(i,j-1,n,m,image,val))
    {
        solve(i,j-1,color,image);
    }
    if(isValid(i,j+1,n,m,image,val))
    {
        solve(i,j+1,color,image);
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        solve(sr,sc,color,image);
        return image;
    }
};