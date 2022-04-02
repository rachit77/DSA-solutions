class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
     // approach:
     // find the row in which the target lies
    // use binary sort in the row to fin the target
    // time complexity: m * log(n)
        
        int m,n,i;
        m=matrix.size();   //rows
        n=matrix[0].size();  // columns
        
    int row=-1;  //variable to store the row in which the target is present
        
        for(i=0;i<m;i++)
        {
            if(target<= matrix[i][n-1])
            {
                row=i;
                break;
            }
        }
        
        if(row==-1)
            return false;
        
        int l=0,h=n-1,mid;
        
        while(l<=h)
        {
            mid=l+(h-l)/2;
            
            if(matrix[row][mid]==target)
                return true;
            
            if(matrix[row][mid] < target)
            {
                l=mid+1;
            }
            else {
                h=mid-1;
            }
        }
        
        
        return false;
        
    }
};