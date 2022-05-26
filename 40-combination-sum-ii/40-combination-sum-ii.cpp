class Solution {
public:
    void find_combinations(int idx,vector<vector<int>> &ans, vector<int> &temp,int target, vector<int>& candidates)
    {    
        if(target==0){
          ans.push_back(temp);
          return;   
        }
        
        if(target<0 || idx==candidates.size()) return;
        
        for(int i=idx;i<candidates.size();i++)
        {
            if(i!=idx && candidates[i]==candidates[i-1]) continue;
            
            if(candidates[i]> target) break;
            
            temp.push_back(candidates[i]);
            find_combinations(i+1,ans,temp,target-candidates[i],candidates);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
       find_combinations(0,ans,temp,target, candidates);
        return ans;
    }
};