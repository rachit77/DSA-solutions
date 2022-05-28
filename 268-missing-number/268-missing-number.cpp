class Solution {
public:
    
    int missingNumber(vector<int>& nums) {

        int i,n=nums.size(),ans=0;
        
        for(i=0;i<=n;i++)
           ans=ans ^ i;
        
        for(i=0;i<n;i++)
            ans= ans ^ nums[i];
        
        return ans;
            
    }
};