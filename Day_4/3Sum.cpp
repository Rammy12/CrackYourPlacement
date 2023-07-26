/* problem:- https://leetcode.com/problems/3sum/description/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            int a=nums[i];
            int t=-a;
            int s=i+1;
            int e=nums.size()-1;
            while(s<e)
            {
                if(nums[s]+nums[e]==t)
                {
                    ans.push_back({nums[i],nums[s],nums[e]});
                    while(s<e and nums[s]==nums[s+1])
                    {
                        s++;
                    }
                    while(s<e and nums[e]==nums[e-1])
                    {
                        e--;
                    }
            
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]>t)
                {
                    e--;
                }
                else
                {
                    s++;
                }
            }
            while(i+1<nums.size() and nums[i+1]==nums[i])
            {
                i++;
            }
        }
        return ans;
    }
};