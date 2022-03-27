class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>> ans;
        int i,n=mat[0].size();
        
        
        for(i=0;i<mat.size();i++) {
            int temp=0;
            
            for(int j=0;j<n;j++) {
                if(mat[i][j]==1)
                    temp++;
                else
                    break;
            }
            
            ans.push_back({temp,i});
        }
        
        //sort in asc order
        
        sort(ans.begin(), ans.end());
        
        while(k<mat.size())
        {
            ans.pop_back();
            k++;
        }
        
        
        vector<int> an;
        for(i=0;i<ans.size();i++)
        {
           // cout<<ans[0].first<<" "<<ans[0].second<<endl;
           an.push_back(ans[i].second); 
        }
        return an;
    }
};