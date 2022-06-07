class Solution {
public:
    bool find(int i,vector<int>& nums, int dp[])
    {
        if(dp[i]!=-1) return dp[i];
        if(i>=nums.size()-1) return true;
        
        for(int t=1;t<=nums[i];t++)
        {
            if( find(i+t, nums,dp) ) return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp,-1,sizeof(dp));
        return find(0,nums,dp);
    }
};