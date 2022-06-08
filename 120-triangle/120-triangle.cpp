class Solution {
public:
    //method-1 memoization sc:o(n^2)
//     int find(int level,int x, vector<vector<int>>& nums, vector<vector<int>> &dp)
//     {
//         if(x>level) return INT_MAX;
//         if(level==nums.size()) return 0;
//         if(dp[level][x]!=-1) return dp[level][x];
        
        
//         int a=find(level+1,x,nums,dp);
//         int b=find(level+1,x+1,nums,dp);
        
//         return dp[level][x]=nums[level][x]+min(a,b);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//        int l=triangle.size();
//         vector<vector<int>> dp(l,vector<int> (l,-1));
//         return find(0,0,triangle,dp);
//     }
    
    //method-2
    int minimumTotal(vector<vector<int>>& triangle) {
    int l=triangle.size();
    if(l==1) return triangle[0][0];
    
    vector<int> dp(l);
    dp=triangle[l-1];
    
    for(int i=l-2;i>=0;i--)
    {
        int siz=triangle[i].size();
        for(int j=0;j<siz;j++)
        {
          dp[j]=triangle[i][j] + min(dp[j],dp[j+1]);
        }
    }
    
    return dp[0];
    }
};