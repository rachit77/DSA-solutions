class Solution {
public:
    vector<int> getRow(int r) {
        
        vector<int> ans(r+1,1);
        vector<int> temp(r+1,1);
        
        for(int i=2;i<=r;i++) //number of row
        {
            for(int j=1;j<i;j++)// transversing over each row
            {
                temp[j]=ans[j]+ans[j-1];
            }
            ans=temp;
        }
        return ans;
    }
};