class Solution {
public:
    // method-1 memoization
//     bool find(int i,vector<int>& nums, int dp[])
//     {
//         if(dp[i]!=-1) return dp[i];
//         if(i>=nums.size()-1) return true;
        
//         for(int t=1;t<=nums[i];t++)
//         {
//             if( find(i+t, nums,dp) ) return dp[i]=true;
//         }
//         return dp[i]=false;
//     }
//     bool canJump(vector<int>& nums) {
//         int dp[nums.size()];
//         memset(dp,-1,sizeof(dp));
//         return find(0,nums,dp);
//     }
    
    // method-2 O(n) time 
    bool canJump(vector<int>& nums) {
        int idx=0,i;
        
        for(i=0;i<nums.size();i++)
        {
            if(i>idx) return false;
                
                idx=max(idx,i+nums[i]);
            
            if(i>=nums.size()-1) return true;
        }
        
     return false;   
        
    }
};