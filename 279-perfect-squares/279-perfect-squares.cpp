class Solution {
public:
    
    int find(int n, int dp[])
    {
        if(dp[n]!=-1) return dp[n];
        
        if(n==0) return 0;
        
        int i=1,ans=INT_MAX;
        
        while(i*i <=n)
        {
           int k= find(n- i*i,dp);
            ans=min(ans,k+1);
            i++;
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return find(n,dp);
        
    }
};