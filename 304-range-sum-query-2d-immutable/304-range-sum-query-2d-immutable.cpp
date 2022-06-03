class NumMatrix {
    
//private:
    vector<vector<int>> data;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        data=matrix;
        
        //club colomn of matrix
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                data[i][j]=data[i][j] + data[i-1][j];
                
            }
        }
        
        for(int i=1;i<matrix[0].size();i++) // i->column
        {
            for(int j=0;j<matrix.size();j++) // j-> row
            {
                data[j][i]= data[j][i] + data[j][i-1];
            }
        }

        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        
        
    sum= data[row2][col2];
        
        if(row1>0) sum-=data[row1-1][col2];
        if(col1>0) sum-=data[row2][col1-1];
        
        if(row1>0 && col1>0) sum+=data[row1-1][col1-1];
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */