class Solution {
public:
    bool find(int i, int j, int idx,vector<vector<char>>& board, string word)
    {
        if(idx==word.length()) return true;
        int r=board.size();
        int c=board[0].size();
        
        if(i<0 || j<0 || i>=r || j>=c || board[i][j]!=word[idx] || board[i][j]=='.') return false;
        
        char temp=board[i][j];
        board[i][j]='.';
        
 if(find(i+1,j,idx+1,board,word) || find(i-1,j,idx+1,board,word) || find(i,j+1,idx+1,board,word) || find(i,j-1,idx+1,board,word)) return true;
       
        board[i][j]=temp;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(find(i,j,0,board,word)) return true;
                }
            }
        }
        return false;
        
    }
};