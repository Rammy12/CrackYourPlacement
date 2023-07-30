/* problem:- https://leetcode.com/problems/add-binary/description/
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i=size(a)-1;
        int j=size(b)-1;
        int carry=0;
        int sum=0;
        while(i>=0 or j>=0)
        {
            int sum=carry;
            if(i>=0)
            {
                sum+=a[i--]-'0';
            }
            if(j>=0)
            {
                sum+=b[j--]-'0';
            }
            if(sum>1)
            {
                carry=1;
            }
            else{
                carry=0;
            }
            ans+=to_string(sum%2);
        }
        if(carry)
        {
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};