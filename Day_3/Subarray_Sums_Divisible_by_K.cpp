/*
Problem:- https://leetcode.com/problems/subarray-sums-divisible-by-k/
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        int n=nums.size();
        int pre_sum=0;
        umap[0]=1;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            pre_sum+=nums[i];
            if(pre_sum<0)
            {
                pre_sum+=ceil(abs(pre_sum)*1.0/k)*k;
            }
            pre_sum%=k;
            if(umap.find(pre_sum)!=umap.end())
            {
                ans+=umap[pre_sum];
            }
            umap[pre_sum]++;
        }
        return ans;
    }
};