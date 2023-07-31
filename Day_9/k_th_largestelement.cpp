/*
problem:- https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        /*sort(nums.begin(),nums.end());
        return nums[n-k];
        using sort take time complexity n(logn)


        using heap time complexity n(logk)
        */
        priority_queue <int, vector<int>, greater<int> > minHeap;
        for(int i=0; i<n; i++)
        {
            minHeap.push(nums[i]);
            if(minHeap.size()>k)
            {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};