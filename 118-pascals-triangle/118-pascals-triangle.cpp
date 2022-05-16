class Solution {
public:
    vector<int> solve(int k,vector<vector<int>> &ans)
    {
        vector<int> temp;
       for(int i=0;i<k;i++)
       {
           if(i==0 || i==k-1)
               temp.push_back(1);
           else {
               int num= ans[k-2][i-1] + ans[k-2][i];
               temp.push_back(num);
           }
           
       }
        return temp;
    }
    
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=1;i<=numRows; i++)
        {
            vector<int> temp=solve(i,ans);
            ans.push_back(temp);
        }
        
        return ans;
    }
};