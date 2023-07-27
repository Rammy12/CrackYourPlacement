/* problem:- https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ans=0;
        int sum=0;
        int window_size=n-k;
        int i=0;
        int c=0, j=0;
        for(j=0; c<n-k; j++,c++)
        {
            sum+=cardPoints[j];
        }
        int t_sum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        ans=max(ans,t_sum-sum);
        while(j<n)
        {
            sum-=cardPoints[i++];
            sum+=cardPoints[j++];
            ans=max(ans,t_sum-sum);
        }
        return ans;
    }
};