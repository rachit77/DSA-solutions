class Solution {
public:
    int countVowelStrings(int n) {
        
        
        vector<vector<int>> dp(n+1,vector<int> (6));
        
        int i,j;
        
       
        
        for(i=0;i<=5;i++)
          dp[1][i]=1;
        
         for(i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        
        
        
        
        for(int i=2;i<=n;i++)
        {
            for(j=1;j<=5;j++)
            {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        
        
        //compute the answer
        
        int ans=0;
        
        for(i=1;i<=5;i++)
            ans = ans + dp[n][i];
        
        return ans;
    }
};