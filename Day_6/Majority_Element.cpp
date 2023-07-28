/* problem :- https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        for(auto e:mp)
        {
            if(e.second>n/2)
            {
                ans=e.first;
            }
        }
        return ans;
    }
};