class Solution {
public:
//     bool is_safe(int r, int c, vector<string> &temp, int &n)
//     {
//         int x=r,y=c;
//         //check upper left diagonal
//         while(r>=0 && c>=0)
//         {
//             if(temp[r][c]=='Q')
//                 return false;
            
//             r--;
//             c--;
//         }
        
//         // check left horizontal line
// //         r=x,c=y;
// //         while(r>=0 && c>=0)
// //         {
// //             if(temp[r][c]=='Q') return false;
            
// //             c--;
// //         }
        
//         //check lower left diagonal
//         r=x,c=y;
//         while(r>=0 && c>=0)
//         {
//             if(temp[r][c]=='Q') return false;
//             r++;
//             c--;
//         }
        
//         return true;
//     }
    
    void solve(int col, vector<string> &temp, vector<vector<string>> &ans, int &n, vector<int> &row, vector<int> &ud, vector<int> &ld)
    {
        if(col==n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
          if(row[i]==0 && ld[i+col]==0 && ud[n-1 + col -i]==0)
          {
              temp[i][col]='Q';
              row[i]=1;
              ld[i+col]=1;
              ud[n-1 + col -i]=1;
              
              solve(col+1,temp,ans,n,row,ud,ld);
              
              temp[i][col]='.';
              row[i]=0;
              ld[i+col]=0;
              ud[n-1 + col -i]=0;
          }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> temp(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            temp[i]=s;
        vector<int> row(n,0);
        vector<int> ud(2*n-1,0);
        vector<int> ld(2*n-1,0);
        
        solve(0,temp,ans,n,row,ud,ld);  // col, temp,ans,n
        
        return ans;
        
    }
};