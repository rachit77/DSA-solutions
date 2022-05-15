class Solution {
public:
    void dfs(int row, int col,vector<vector<char>>& board )
    {
        
        if(row<0 || col<0 || row>= board.size() || col >= board[0].size())
            return;
        
        if(board[row][col]!='O')
            return;
        
        board[row][col]='1';
        
        dfs(row+1,col,board);
        dfs(row-1,col,board);
        dfs(row,col+1,board);
        dfs(row,col-1,board);
        
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        
        
        int row= board.size(), col=board[0].size();
        
        // first and last row
        for(int i=0;i<col;i++)
        {
            dfs(0,i,board);
            dfs(row-1,i,board);
        }
        
        // first and last column
        for(int i=0;i<row;i++)
        {
            dfs(i,0,board);
            dfs(i,col-1,board);
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='1')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
};