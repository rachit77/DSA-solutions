class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //method-1 GREEDY APPROACH
        // stack<int> st;
        // int profit=0;
        // for(int i=0;i<prices.size();i++)
        // {
        //     if(!st.empty() && prices[i]>st.top())
        //     {
        //         profit+= prices[i]-st.top();
        //         while(!st.empty() && prices[i]>=st.top())
        //             st.pop();
        //     }
        //      st.push(prices[i]);    
        // }
        // return profit;
        
        //method-2 valley peak approach
        int ans=0,i;
        for(i=1;i<prices.size();i++)
        {
            ans+=max(prices[i]-prices[i-1],0);
        }
        return ans;
    }
};