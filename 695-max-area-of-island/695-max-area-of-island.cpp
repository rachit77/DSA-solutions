class Solution {
public:
    vector<int> row={0,0,1,-1};
    vector<int> col={1,-1,0,0};
    
    int dfs(int i,int j, vector<vector<int>>& grid,vector<vector<bool>>& vis)
    {
        //check i and j are in limits
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==true ) return 0;
        
        vis[i][j]=true;
        
        int area=0,temp=0;
        for(int t=0;t<4;t++)
        {
            int new_row=row[t]+i;
            int new_col=col[t]+j;
          
            //area=max(area, 1+dfs(new_row, new_col,grid,vis));
            temp+=dfs(new_row, new_col,grid,vis);
        }
        
        area=1+max(area,temp);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        vector<vector<bool>> vis(r, vector<bool>(c,false));
        
        int area=0;
        
        // transverse on the grid to calculate the islands
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==false)
                {
                    area=max(area,dfs(i,j,grid,vis));
                }
            }
        }
        
        return area;
        
    }
};