class Solution {
public:
    
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};
    
int find(int i,int j, vector<vector<int>> &rec,vector<vector<int>>& matrix, int par)
{
    int r=matrix.size();
    int c= matrix[0].size();
    
    //if out of bounds return 0
    if(i<0 || j<0 || i>=r || j>=c || par>= matrix[i][j]) return 0;
    
    //if already visited
    if( rec[i][j] !=-1 )
        return rec[i][j];
    
    int a=INT_MIN;
    for (int k=0; k<4; k++)
    {
        int I = i + dx[k];
        int J = j + dy[k];
        
        a=max(a,1+find(I,J,rec,matrix,matrix[i][j]));
    }
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