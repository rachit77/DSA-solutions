class Solution {
     
public:
     int sum(vector<int> &v)
    {
        int s=0;
        for(auto x:v)
            s+=x;
            
        return s;
    }
    vector<vector<int>> ans;
    void findCombination(int prev, int n,int k, vector<int> &temp)
    {
        if(k==0)
        {
            int t= sum(temp);
            if(t==n)
                ans.push_back(temp);
            return;
        }
        
        for(int i=prev;i<=9;i++)
        {
            temp.push_back(i);
            findCombination(i+1,n,k-1,temp);
            
            temp.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
       findCombination(1,n,k,temp);
        
        return ans;  
    }
};