class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i,ans=0,temp=0;
        
        for(i=0;i<nums.size();i++)
        {
           if(nums[i]==1)
           {
               temp++;
           }
            else
            {
                ans=max(ans,temp);
                temp=0;
            }
        }
        
        return max(ans,temp);
        
    }
};