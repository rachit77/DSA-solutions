class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        int i=0;
        vector<int> ans;
        
        for(auto x:m)
        {
            if(x.second > nums.size()/3)
            {
                
                ans.push_back(x.first);
            }
                
        }
        
        
        
        return ans;
        
    }
};