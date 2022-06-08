class Solution {
public:
    int find(int level,int x, vector<vector<int>>& nums, vector<vector<int>> &dp)
    {
        if(x>level) return INT_MAX;
        if(level==nums.size()) return 0;
        if(dp[level][x]!=-1) return dp[level][x];
        
        
        int a=find(level+1,x,nums,dp);
        int b=find(level+1,x+1,nums,dp);
        
        return dp[level][x]=nums[level][x]+min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       int l=triangle.size();
        vector<vector<int>> dp(l,vector<int> (l,-1));
        return find(0,0,triangle,dp);
    }
};