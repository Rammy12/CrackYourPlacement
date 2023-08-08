/*
problem:- https://leetcode.com/problems/valid-parentheses/
*/


class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int n=s.length();
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty() or (st.top()=='(' and s[i]!=')') or (st.top()=='{' and s[i]!='}') or (st.top()=='[' and s[i]!=']'))
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};