/*
problem:- https://leetcode.com/contest/weekly-contest-357/problems/faulty-keyboard/
*/

class Solution {
public:
    string finalString(string s) {
        int n=s.length();
        string ans="";
        for(int j=0; j<n; j++)
        {
            char c=s[j];
            if(c=='i')
            {
                reverse(ans.begin(),ans.end());
            }
            else
            {
                ans+=c;
            }
        }
        return ans;
    }
};