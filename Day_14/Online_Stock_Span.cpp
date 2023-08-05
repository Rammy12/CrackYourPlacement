/*
problem:- https://leetcode.com/problems/online-stock-span/
*/

lass StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int result=1;
        while(!st.empty() and st.top().first<=price)
        {
            result+=st.top().second;
            st.pop();
        }
        st.push({price,result});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */