class Solution {
public:
    //method-3
   int find(int i,int hold,vector<int> &prices, vector<vector<int>> &dp)
   {
       if(i==prices.size()) return 0;
       
       if(dp[i][hold]!=-1) return dp[i][hold];
       
       int profit;
       
       if(hold==0) //not holding any stock
       {
           //case 1 : buy the current stock
           int a=find(i+1,1,prices,dp) -prices[i];
           
           //case 2: skip the stock
           int b=find(i+1,0,prices,dp);
           
           profit=max(a,b);
           
       }
       else  //holding a stock
       {
           //case 1: sell the stock
           int a=find(i+1,0,prices,dp)+prices[i];
           
           //case 2: skip the stock
           int b=find(i+1,1,prices,dp);
           
           profit=max(a,b);
       }
       
       return dp[i][hold]=profit;
   }
    
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
        // int ans=0,i;
        // for(i=1;i<prices.size();i++)
        // {
        //     ans+=max(prices[i]-prices[i-1],0);
        // }
        // return ans;
        
        //method-3 recursion and memoization
        
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return find(0,0,prices,dp);
    }
};