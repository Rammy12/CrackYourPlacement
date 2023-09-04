/*
problem :- https://leetcode.com/contest/weekly-contest-361/problems/count-symmetric-integers/
*/

class Solution {
public:
    int getsum(string s)
    {
        int n=s.size();
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=s[i]-48;
        }
        return sum;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        while(low<=high)
        {
            string s=to_string(low)+"";
            if(s.length()%2==0)
            {
                int len=s.size();
                int mid=len/2;
                string first=s.substr(0,mid);
                string last=s.substr(mid,len);
                int sum1=getsum(first);
                int sum2=getsum(last);
                if(sum1==sum2)
                {
                    ans++;
                }
            }
            low++;
        }
        return ans;
    }
};