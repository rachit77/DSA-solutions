class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        int n= nums.size();
        
        for(int i=0;i<n;i++) {
            sum+=nums[i];
        }
        
        if(sum%2==1)
        return false;
        
        sum=sum/2;
        
        long int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n+1;i++)
            dp[i][0]=1;
        
        
        for(int i=1;i<sum+1;i++)
            dp[0][i]=0;
        
        
        //fill the dp
        for(int i=1;i<n+1;i++) // array
        {
            for(int j=1;j<sum+1;j++) //sum
            {
                if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                
                else
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        
        return (dp[n][sum]>0)? true: false;
    }
};