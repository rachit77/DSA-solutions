class Solution {
public:
    
int fillMatrix(int i, int n, vector<vector<int>> &ans,int x,int y, char ch)
    {
        if(x<0 || y<0 || x>=n || y>=n || ans[x][y]!=-1)
            return -1;
        
        ans[x][y]=i;
    //cout<<x<<y<<i<<endl;
    
    if(ch=='R')
        y=y+1;
    else if(ch=='L')
        y=y-1;
    else if(ch =='U')
        x=x-1;
    else
        x=x+1;
        
        int temp= fillMatrix(i+1,n,ans,x,y,ch);
        
        if(temp==-1)
        {
            if(ch=='R')
            {
                ch='D';
                y=y-1;
                x=x+1;
            }
            else if(ch=='L')
            {
                ch='U';
                y=y+1;
                x=x-1;
            }
            else if(ch =='U')
            {
               ch='R'; 
                x=x+1;
                y=y+1;
            }
            else
            {
                ch='L';
                x=x-1;
                y=y-1;
            }
            
            fillMatrix(i+1,n,ans,x,y,ch);
        }
    
      return 0;
    }
    
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n,-1));
        
//         int ans[n][n];
//         memset(ans,-1, sizeof(ans));
        
        fillMatrix(1,n,ans,0,0,'R');
        
        return ans;
        
    }
};