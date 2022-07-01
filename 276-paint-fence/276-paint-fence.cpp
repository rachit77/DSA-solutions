class Solution {
public:
    int find(int i,int k, vector<int> &dp)
    {
        if(i==1) return k;
        if(i==2) return k*k;
        
        if(dp[i]!=-1) return dp[i];
        
        return dp[i]=(k-1)*(find(i-1,k,dp)+ find(i-2,k,dp));
        
    }
    int numWays(int n, int k) {
      vector<int> dp(n+1,-1);
       return find(n,k,dp); 
    }
};