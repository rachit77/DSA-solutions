class Solution {
public:
    int subset(vector<int>nums,int sum){
        int n=nums.size();
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int j=1;j<=sum;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
//         int n=nums.size();
//         int i,s=0;
//         for(i=0;i<n;i++)
//             s+=nums[i];
        
        
//         target=abs(target);
        
//       int  new_target=(s+target);
        
            
//              if(new_target%2==1 || s<new_target) return 0;
        
//         new_target=new_target/2;
        
//         //new_target = abs(new_target);
        
        
//         int dp[n+1][new_target+1];
        
//         // fill the dp with some intial values
       
        
//          for(i=0;i<new_target+1;i++)
//             dp[0][i]=0;
        
//         for(i=0;i<n+1;i++)
//             dp[i][0]=1;
        
       
        
//         //cout<<dp[0][0]<<"VF"<<dp[0][1]<<endl;
        
//         // fill the complete
//         for(i=1;i<n+1;i++) {
//             for(int j=1;j<new_target+1;j++) {
                
//                 if(nums[i-1] > j)
//                     dp[i][j]= dp[i-1][j];
                
//                 else {
                
//                 //if(nums[i-1]<=j)
//                     dp[i][j]=dp[i][j] + dp[i-1][j-nums[i-1]];
                    
//             //cout<<"frf"<<dp[i-1][j]<<" "<<dp[i-1][j-nums[i-1]]<<endl;
//                 }
                
//                 //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                
//             }
//         }
        
        
        
//         int ans= dp[n][new_target];
        
//         return ans;
        
        
        int s=0;
        s=accumulate(nums.begin(),nums.end(),s);
        int p=(target+s)/2;
        if(s < target || (s + target) % 2 != 0)
            return 0;
        return subset(nums,abs(p));   
        
    }
};