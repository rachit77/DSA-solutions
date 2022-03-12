class Solution {
public:
   
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int i,s=0;
        for(i=0;i<n;i++)
            s+=nums[i];
        
        
        target=abs(target);
        
       int  new_target=(s+target);
        new_target=new_target/2;
            
       if((s+target)%2==1 || s<new_target) return 0;
     
       //new_target = abs(new_target);
       int dp[n+1][new_target+1];
       
         for(i=0;i<new_target+1;i++) dp[0][i]=0;
        
        for(i=0;i<n+1;i++) dp[i][0]=1;
 

        for(i=1;i<=n;i++) {
            for(int j=0;j<=new_target;j++) {
                 dp[i][j]= dp[i-1][j];
                 if(nums[i-1]<=j)
                    dp[i][j]=dp[i][j] + dp[i-1][j-nums[i-1]];
                
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                   }
        }  
        
        return dp[n][new_target];  
        
    }
};