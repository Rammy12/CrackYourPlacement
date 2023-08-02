/*
problem:- https://leetcode.com/problems/sliding-window-maximum/
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque <int> deq;
        vector <int> res;

        for(int i = 0; i < k; i++){
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(i);
        }
        res.push_back(nums[deq.front()]);

        for(int i = k; i < n; i++){
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(i);
            if(deq.front() == i - k)
            {
                deq.pop_front();
            } 
            res.push_back(nums[deq.front()]);
        }

        return res;
    }
};