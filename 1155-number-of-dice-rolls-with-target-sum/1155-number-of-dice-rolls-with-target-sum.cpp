class Solution {
public:
    const int MOD =1000000007;
    int find(int i,int sum, int &k, int &ans,vector<vector<int>> &dp)
    {
        if(sum==0 && i==0) return 1;
        
         if(sum<=0 || i<=0) return 0;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        int temp=0;
        for(int face=1;face<=k;face++)
        {
            //cout<<sum-k<<endl;
            temp= (temp + find(i-1,sum-face,k,ans,dp)%MOD)%MOD;
        }
        
        return dp[i][sum]=temp;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
        int ans=0;
        ans=find(n,target,k,ans,dp);
        return ans;   
    }
};