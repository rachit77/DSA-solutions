class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        
        int profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(st.empty()) st.push(prices[i]);
            else if(prices[i]<st.top())
            {
                st.push(prices[i]);
            }
            else if(prices[i]>st.top())
            {
                profit+= prices[i]-st.top();
                
                while(!st.empty() && prices[i]>=st.top())
                    st.pop();
                
                st.push(prices[i]);
            }
            
        }
        
        return profit;
        
    }
};