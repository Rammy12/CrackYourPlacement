/*
Problem:- https://leetcode.com/problems/subarray-sum-equals-k/description/
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int sum=0;
        unordered_map<int,int>ump;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            if(sum==k)
            {
                ans++;
            }
            if(ump.find(sum-k)!=ump.end())
            {
                ans+=ump[sum-k];
            }
            ump[sum]++;
        }
        return ans;
    }
};