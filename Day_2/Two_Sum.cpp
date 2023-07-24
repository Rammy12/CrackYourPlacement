/* Problem :- https://leetcode.com/problems/two-sum/description/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>map;
        for(int i=0; i<n; i++)
        {
            int a=nums[i];
            int b=target-a; // a+b=target
            if(map.count(b))
            {
                return {map[b],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};