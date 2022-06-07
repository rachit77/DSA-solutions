class Solution {
public:
    int path(int x,int y, vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
        int r=grid.size();
        int c=grid[0].size();
        
        if(x==r-1 && y==c-1)
           return grid[x][y];
        
        if(x<0 || y<0 || x==r ||y==c) return INT_MAX;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        int a=path(x+1,y,grid,dp);
        int b=path(x,y+1,grid,dp);
        
        return dp[x][y]=grid[x][y]+min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size(),c =grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c,-1));
        return path(0,0,grid,dp);
        
    }
};