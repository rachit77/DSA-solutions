class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //transpose the matrix and reverse all rows
        
        //transpose
        int i,j,n;
        n=matrix.size();
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n/2;j++)
            {
                int temp= matrix[i][j];
                matrix[i][j]=matrix[i][n-j-1];
                matrix[i][n-1-j] = temp;
            }
        }
        
        
        
    }
};