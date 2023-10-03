/*
problem:- https://leetcode.com/problems/number-of-islands/description/
*/

class Solution {
public:
bool isValid(int i,int j,int n,int m,vector<vector<char>>& grid)
{
    if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(int i,int j,int n,int m,vector<vector<char>>& grid)
{
    grid[i][j]='0';
    if(isValid(i-1,j,n,m,grid))
    {
        solve(i-1,j,n,m,grid);
    }
    if(isValid(i+1,j,n,m,grid))
    {
        solve(i+1,j,n,m,grid);
    }
    if(isValid(i,j-1,n,m,grid))
    {
        solve(i,j-1,n,m,grid);
    }
    if(isValid(i,j+1,n,m,grid))
    {
        solve(i,j+1,n,m,grid);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    solve(i,j,n,m,grid);
                }
            }
        }
        return res;
    }
};