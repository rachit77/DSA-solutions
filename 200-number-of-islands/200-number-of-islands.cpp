class Solution {
public:
    int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};
    
    bool valid_index(int i, int j, vector<vector<char>>& grid) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        return true;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j]='0';
        for(int k=0; k<4; k++) {
            int ci=DR[k]+i;
            int cj=DC[k]+j;
            if(!valid_index(ci, cj, grid))
                continue;
            if(grid[ci][cj]=='1')
                dfs(ci, cj, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int no_of_islands=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1') {
                    no_of_islands++;
                    dfs(i, j, grid);
                }
            }
        }
        return no_of_islands;
        
    }
};