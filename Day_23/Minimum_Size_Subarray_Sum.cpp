/*
problem:- https://leetcode.com/problems/minimum-size-subarray-sum/
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int j=0,i=0;
        int sum=0;
        int minL=INT_MAX;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                sum-=nums[i];
                minL=min(minL,j-i+1);
                i++;
            }
            j++;
        }
        if(minL==INT_MAX)
        {
            return 0;
        }
        return minL;
    }
};