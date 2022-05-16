class Solution {
public:
bool isValid(int a , int b,vector<vector<int>>& vis, vector<vector<int>>& grid)
    {
      if(a<0 || b<0 || a>=grid.size() || b>=grid.size() || vis[a][b]==1 || grid[a][b]==1)
          return false;
                                                                            return true;
    }
                                                                                
                                                                                
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
       int n= grid.size();
        
       vector<vector<int>> vis(n, vector<int> (n,0));
        
        queue<pair<int,int>> q;
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1)  return -1;
        
        q.push({0,0});
        vis[0][0]=1;
        
        int ans=0;
       
        while(!q.empty())
        {
            int s=q.size();
            ans++; //level increases
            
            for(int i=0;i<s;i++)
            {
                int a=q.front().first;
                int b=q.front().second;
                
                if(a==n-1 && b==n-1) return ans;
                q.pop();
                
                for(int k=a-1;k<=a+1;k++)
                {
                    for(int l=b-1; l<=b+1;l++)
                    {
                        if( isValid(k,l,vis,grid) )
                         {
                            vis[k][l]=1;
                            q.push({k,l});
                         }
                    }
                }
                
                
            }
        }
        
        return -1;
        
    }
};