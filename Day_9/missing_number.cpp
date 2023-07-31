/* problem:- https://leetcode.com/problems/missing-number/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        vector<bool>isVisited(n+1,false);
        for(int i=0; i<n; i++)
        {
            isVisited[nums[i]]=true;
        }
        for(int i=0; i<isVisited.size(); i++)
        {
            if(isVisited[i]==false)
            {
                ans=i;
            }
        }
        return ans;
    }
};