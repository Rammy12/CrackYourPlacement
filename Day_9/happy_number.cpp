/*
problem:- https://leetcode.com/problems/happy-number/
*/

class Solution {
public:
int fun(int n)
{
    int sum=0;
    while(n)
    {
        int rem=n%10;
        sum+=rem*rem;
        n=n/10;
    }
    return sum;
}
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1 and !s.count(n))
        {
            s.insert(n);
            n=fun(n);
        }
        return n==1;

    }
};