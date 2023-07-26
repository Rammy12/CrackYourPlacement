/*
problem:- https://leetcode.com/problems/container-with-most-water/description/
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int w=end-start;
            int l=min(height[start],height[end]);
            int area=w*l;
            ans=max(area,ans);
            if(height[start]<height[end])
            {
                start++;
            }
            else if(height[start]>height[end])
            {
                end--;
            }
            else
            {
                start++;
                end--;
            }
        }
        return ans;
    }
};