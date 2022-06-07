class Solution {
public:
    //method-1 memoization
//     int find(int n, int dp[])
//     {
//         if(dp[n]!=-1) return dp[n];
        
//         if(n==0) return 0;
        
//         int i=1,ans=INT_MAX;
        
//         while(i*i <=n)
//         {
//            int k= find(n- i*i,dp);
//             ans=min(ans,k+1);
//             i++;
//         }
//         return dp[n]=ans;
//     }
//     int numSquares(int n) {
        
//         int dp[n+1];
//         memset(dp,-1,sizeof(dp));
//         return find(n,dp);
        
//     }
    
    
    int numSquares(int n){
        //method-2 dp
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        
        int cnt=1;
        while(cnt*cnt <=n)
        {
            int temp=cnt*cnt;
            for(int i=temp;i<=n;i++)
            {
                dp[i]=min(dp[i], 1+dp[i-temp]);
            }
            cnt++;
        }
        
        return dp[n];
    }
};