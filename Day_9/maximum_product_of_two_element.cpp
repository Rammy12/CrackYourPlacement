/*
problem:- https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        priority_queue <int, vector<int>, greater<int> >minHeap;
        for(int i=0; i<n; i++)
        {
            minHeap.push(nums[i]);
            if(minHeap.size()>2)
            {
                minHeap.pop();
            }
        }
        while(minHeap.size())
        {
            ans*=minHeap.top()-1;
            minHeap.pop();
        }
        return ans;
    }
};