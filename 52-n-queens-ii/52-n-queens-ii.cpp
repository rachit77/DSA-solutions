class Solution {
public:
    
   bool check(int r,int c,vector<int> &row, vector<vector<int>> &board)
   {
       int n=row.size();
       if(row[r]==1) return false;
       
       int x=r,y=c;
       
       // left diagonal upward
       while(x>=0 && y>=0)
       {
           if(board[x][y]==1) return false;
           
           x--;
           y--;
       }
       
       x=r,y=c;
       // left diagonal downward
       while(y>=0 && x<=n-1)
       {
           if(board[x][y]==1) return false;
           x++;
           y--;
       }
       return true;
       
   }
    
   void path(int i, vector<int> &r, int &n, int &cnt, vector<vector<int>> &board)
    {
        if(i==n){
           cnt++;
            return;
        } 
        
        //i-th column
        for(int t=0;t<n;t++)
        {
            if(check(t,i,r,board))
            {
                board[t][i]=1;
                r[t]=1;
                path(i+1,r,n,cnt,board);
                board[t][i]=0;
                r[t]=0;
            }
        }
        return;
    }
    int totalNQueens(int n) {
        
        int i=0;
        int cnt=0;
        vector<vector<int>> board(n,vector<int> (n,0) );
        
        vector<int> r(n,0);
        path(i,r,n,cnt, board);
            
            return cnt;
    }
};