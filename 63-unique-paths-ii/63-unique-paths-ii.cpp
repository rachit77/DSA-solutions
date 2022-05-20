class Solution {
public:
    int find(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        int r= grid.size();
        int c= grid[0].size();
        //cout<<r<<c<<endl;
    
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==1) return 0;
        
        if(vis[i][j]!=-1) return vis[i][j];
        
        if(i== grid.size()-1 && j==grid[0].size()-1)
        {
            return 1;
        }
        
        int a= find(i,j+1,vis,grid); //right
        int b= find(i+1,j,vis,grid);  //down
        
        //cout<<i<<" "<<j<<" "<<a+b<<endl;
            
        return vis[i][j]=a+b;    
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int r= grid.size();
        int c= grid[0].size();
        
        vector<vector<int>> vis(r, vector<int> (c,-1));
        int ans;
        
        ans=find(0,0,vis,grid);
        return ans;
        
    }
};