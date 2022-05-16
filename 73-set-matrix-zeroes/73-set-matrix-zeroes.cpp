class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
     bool fr=false,fc=false;
        
        int r,c;
        r=matrix.size();
        c=matrix[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0) fr=true;
                    if(j==0) fc=true;
                    
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        for( int i=0;i<c;i++)
        {
            if(fr==true)
                matrix[0][i]=0;
        }
        
        
        for( int i=0;i<r;i++)
        {
            if(fc==true)
                matrix[i][0]=0;
        }
    }
};