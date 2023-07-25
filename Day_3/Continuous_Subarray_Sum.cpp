/*
Problem:- https://leetcode.com/problems/continuous-subarray-sum/description/
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        int n=nums.size();
        int pre_sum=0;
        umap[0]=-1;
        for(int i=0; i<n; i++)
        {
            pre_sum+=nums[i];
            pre_sum%=k;
            if(umap.find(pre_sum)!=umap.end())
            {
                if(i-umap[pre_sum]>1)
                {
                    return true;
                }
            }
            else{
                umap[pre_sum]=i;
            }
            
        }
        return false;
    }
};