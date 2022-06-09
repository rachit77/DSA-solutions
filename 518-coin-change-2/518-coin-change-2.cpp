class Solution {
public:
    int find(int amt, vector<int> &coins, int i,vector<vector<int>> &dp)
    {
        if(amt==0) return 1;
        if(amt<0 || i>=coins.size()) return 0;
        if(dp[amt][i]!=-1) return dp[amt][i];
        
        //if(dp[amt]!=-1) return dp[amt];

        return dp[amt][i]=find(amt-coins[i],coins,i,dp) + find(amt,coins,i+1,dp);
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n,-1));
        
       return find(amount, coins,0,dp);
    }
};