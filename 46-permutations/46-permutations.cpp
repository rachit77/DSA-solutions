class Solution {
public:
    void find(int id, vector<vector<int>> &ans,vector<int>& nums)
    {
       if(id==nums.size())
       {
           ans.push_back(nums);
           return;
       }
        
        for(int i=id;i<nums.size();i++)
        {
            swap(nums[id],nums[i]);
            find(id+1,ans,nums);
            swap(nums[id], nums[i]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        find(0,ans,nums);
        return ans;
        
    }
};