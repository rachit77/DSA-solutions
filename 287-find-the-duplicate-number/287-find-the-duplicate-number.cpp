class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int i,n=nums.size(),k;
        
        for(i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                k= nums[i];
                break;
            }
        }
        
        return k;
        
    }
};