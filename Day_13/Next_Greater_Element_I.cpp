/*
problem:- https://leetcode.com/problems/next-greater-element-i/
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>umap;
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        stack<int>st;
        for(int i=m-1; i>=0; i--)
        {
            while(!st.empty() and st.top()<=nums2[i])
            {
                st.pop();
            }
            int res=(st.empty()) ? -1: (st.top());
            umap[nums2[i]]=res;
            st.push(nums2[i]);
        }
        for(int i=0; i<n; i++)
        {
            if(umap.find(nums1[i])!=umap.end())
            {
                ans.push_back(umap[nums1[i]]);
            }
        }
        return ans;
    }
};