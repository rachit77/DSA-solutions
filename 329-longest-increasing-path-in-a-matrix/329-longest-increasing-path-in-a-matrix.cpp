class Solution {
public:
int find(int i,int j, vector<vector<int>> &rec,vector<vector<int>>& matrix, int par)
{
    int r=matrix.size();
    int c= matrix[0].size();
    
    //if out of bounds return 0
    if(i<0 || j<0 || i>=r || j>=c) return 0;
    
    if(par>= matrix[i][j]) return 0;
    
    //if already visited
    if( rec[i][j] !=-1 )
        return rec[i][j];
    
    //left
    int a=1+find(i,j-1,rec,matrix,matrix[i][j]);
    
    //right
    a=max(a,1+find(i,j+1,rec,matrix,matrix[i][j]));
    
    //up
    a=max(a,1+find(i-1,j,rec,matrix,matrix[i][j]));
    
    //down
    a= max(a,1+find(i+1,j,rec,matrix,matrix[i][j]));
    
    return rec[i][j]=a;
}
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c= matrix[0].size();
        vector<vector<int>> rec(r, vector<int> (c,-1));
        
        int ans=1;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
               if(rec[i][j]==-1)
               {
                   int temp=find(i,j,rec,matrix,-1);
                   ans= max(ans,temp);
               }
            }
        }
        
        
        return ans;
    }
};