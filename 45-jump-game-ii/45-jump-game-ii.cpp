class Solution {
public:
    int find(int i, vector<int>& nums, int dp[])
    {
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int temp=100000;
        
        for(int t=1;t<=nums[i];t++)
        {
            temp=min(temp,find(i+t,nums,dp));
        }
        
        return dp[i]=1+temp;
    }
    
    int jump(vector<int>& nums) {
        
        int dp[nums.size()+1];
        memset(dp,-1,sizeof(dp));
        
        return find(0,nums,dp);  
    }

};