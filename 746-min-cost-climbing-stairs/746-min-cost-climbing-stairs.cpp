class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       
        int n=cost.size();
        vector<int> dp(n);
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2;i<n;i++)
        {
            dp[i]=cost[i]+ min(dp[i-1],dp[i-2]);
        }
        // ans is min of last two
        //cout<<dp[3]<<endl;
        // for(auto it:dp)
        //     cout<<it<<endl;
        int ans=0;
        ans=min(dp[n-1],dp[n-2]);
        return ans;
    }
};