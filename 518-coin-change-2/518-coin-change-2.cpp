class Solution {
public:
    //method-1 memoization
//     int find(int amt, vector<int> &coins, int i,vector<vector<int>> &dp)
//     {
//         if(amt==0) return 1;
//         if(amt<0 || i>=coins.size()) return 0;
//         if(dp[amt][i]!=-1) return dp[amt][i];
//         return dp[amt][i]=find(amt-coins[i],coins,i,dp) + find(amt,coins,i+1,dp);
//     }
    
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<vector<int>> dp(amount+1, vector<int>(n,-1)); 
//        return find(amount, coins,0,dp);
//     }
    
    //method-2 tabulation
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,0));
        
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=coins[i-1])
                {
                    dp[i][j]+=dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};