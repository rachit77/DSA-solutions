class Solution {
public:
    
    int dp[51][51][51];
    int mod=1e9 +7;
    
    int total(int x,int y,int m,int n, int maxMove)
    {
        
        if(x<0 || x==n || y<0 || y==m)
        {
            return 1;
        }
        
        if(maxMove==0)
            return 0;
        
        if(dp[x][y][maxMove]!=-1)
            return dp[x][y][maxMove];
        int ans=0;     
        ans = (ans + total(x+1,y,m,n,maxMove-1))% mod;
        ans=(ans + total(x-1,y,m,n,maxMove-1))% mod;
        ans= (ans + total(x,y+1,m,n,maxMove-1))% mod;
        ans = (ans+ total(x,y-1,m,n,maxMove-1))% mod;
        
        return dp[x][y][maxMove]=ans;
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)     {
        
        memset(dp,-1,sizeof(dp));
        
        return total(startColumn,startRow, m,n, maxMove);
    }
};