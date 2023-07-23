/*Problem:- https://leetcode.com/problems/move-zeroes/description/
*/




class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zerocount=0;
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {
                zerocount++;
                continue;
            }
            nums[j++]=nums[i];
        }
        while(zerocount)
        {
            nums[j++]=0;
            zerocount--;
        }
    }
};