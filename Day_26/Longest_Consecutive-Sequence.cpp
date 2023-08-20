/*
problem:- https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>us;
        for(int i=0; i<n; i++)
        {
            us.insert(nums[i]);
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(us.find(nums[i]-1)!=us.end())
            {
                continue;
            }
            else
            {
                int curr=nums[i];
                int j=0;
                while(us.find(curr)!=us.end())
                {
                    j++;
                    curr++;
                }
                ans=max(ans,j);
            }
        }
        return ans;
    }
};