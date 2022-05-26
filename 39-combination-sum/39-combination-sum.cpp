class Solution {
public:
    void combination(vector<vector<int>> &ans, vector<int> &temp,int idx, int target,vector<int>& candidates)
    {
        if(target<0)
            return;
        if(idx==candidates.size()){
        if(target==0)
            ans.push_back(temp);
        return;
        
        }

        
        //include i
        temp.push_back(candidates[idx]);
        combination(ans,temp,idx,target-candidates[idx],candidates);
         temp.pop_back();
        
//         //excluding i
         combination(ans,temp,idx+1,target, candidates);
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     
        vector<vector<int>> ans;
        vector<int> temp;
        
        combination(ans,temp,0,target,candidates);
        return ans;
        
    }
};