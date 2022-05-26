class Solution {
public:
    void find_combinations(int idx,vector<vector<int>> &ans,vector<int> &temp,vector<int>& nums)
    {
        ans.push_back(temp);
        
        for(int i=idx;i<nums.size();i++)
        {
            if(i!=idx && nums[i]==nums[i-1]) continue;
            
            temp.push_back(nums[i]);
            find_combinations(i+1,ans,temp,nums);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
       find_combinations(0,ans,temp, nums); 
        return ans;
        
    }
};