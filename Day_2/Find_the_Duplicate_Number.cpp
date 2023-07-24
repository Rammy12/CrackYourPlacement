/* Problem :- https://leetcode.com/problems/find-the-duplicate-number/description/
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int, int> umap;
        for(int i=0; i<n; i++)
        {
            umap[nums[i]]++;
        }
        for(auto x:umap)
        {
            if(x.second>1)
            {
                ans=x.first;
            }
        }
        return ans;
    }
};