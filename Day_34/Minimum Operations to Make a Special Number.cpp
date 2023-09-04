/*
problem:- https://leetcode.com/contest/weekly-contest-361/problems/minimum-operations-to-make-a-special-number/
*/

class Solution {
public:
    int dp[101][27];
    int solve(int ind,int num,string &s)
    {
        //base case
        if(ind==s.size())
        {
            if(num%25==0)
            {
                return 0;
            }
            return 1e9;
        }
        if(dp[ind][num]!=-1)
        {
            return dp[ind][num];
        }
        int digit=s[ind]-'0';
        int non_pick=1+solve(ind+1,num,s);
        int pick=solve(ind+1,(num*10+digit)%25,s);
        return dp[ind][num]=min(pick,non_pick);
    }
    int minimumOperations(string num) {
        /*int ans=num.size();
        int n=num.size();
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i-1; j>=0; j--)
            {
                int lastnum=(num[i]-'0')+(num[j]-'0')*10;
                if(lastnum%25==0)
                {
                    ans=min(ans,n-j-2);
                }
            }
            if(num[i]=='0')
            {
                ans=min(ans,n-1);
            }
        }
        return ans;*/
        memset(dp,-1,sizeof(dp));
        return solve(0,0,num);
    }
};