/*
problem:- https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int m=INT_MAX;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            m=min(m,nums[i]);
        }
        for(int x:nums)
        {
            ans+=x-m;
        }
        return ans;
    }
};