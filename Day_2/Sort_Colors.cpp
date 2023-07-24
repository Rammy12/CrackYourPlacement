/* Problem :- https://leetcode.com/problems/sort-colors/description/
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int zeroCount=0;
        int oneCount=0;
        int twoCount=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {
                zeroCount++;
            }
            else if(nums[i]==1)
            {
                oneCount++;
            }
            else
            {
                twoCount++;
            }
        }
        int j=0;
        while(zeroCount)
        {
            nums[j++]=0;
            zeroCount--;
        }
        while(oneCount)
        {
            nums[j++]=1;
            oneCount--;
        }
        while(twoCount)
        {
            nums[j++]=2;
            twoCount--;
        }
    }
};