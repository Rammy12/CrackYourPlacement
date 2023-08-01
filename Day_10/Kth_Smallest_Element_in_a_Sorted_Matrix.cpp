/*
problem:- https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //using maxheap
        /*priority_queue <int> maxHeap;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                maxHeap.push(matrix[i][j]);
                if(maxHeap.size()>k)
                {
                    maxHeap.pop();
                }
            }
        }
        return maxHeap.top();*/

        // using binary search
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low< high)
        {
            int mid=low+(high-low)/2;
            int count=0;
            for(int i=0; i<n; i++)
            {
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
    }
};