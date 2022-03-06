class Solution {
public:
    int countOrders(int n) {
        
        long long int dp[n+1];
        
        memset(dp,1,sizeof(dp));
        
        dp[1]=1;
        const unsigned int M = 1000000007;
        
        //long long int ans=0;
        
        for(int i=2;i<=n;i++)
        {
            int temp=((2*i)*(2*i-1))/2;
            dp[i]=(temp*dp[i-1])% M;
        }
        
        
        
        return dp[n];
        
    }
};