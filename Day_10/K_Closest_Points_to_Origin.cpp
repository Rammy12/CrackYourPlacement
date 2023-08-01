/*
problem:- https://leetcode.com/problems/k-closest-points-to-origin/
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue <pair<int,pair<int,int>>> maxHeap;
        int n=points.size();
        for(int i=0; i<n; i++)
        {
            int dis=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            maxHeap.push(make_pair(dis,make_pair(points[i][0],points[i][1])));
            if(maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }
        while(k)
        {
            int x=maxHeap.top().second.first;
            int y=maxHeap.top().second.second;
            ans.push_back({x,y});
            maxHeap.pop();
            k--;
        }
        return ans;
    }
};