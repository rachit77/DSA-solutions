class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int one_cnt=0;
        for(auto it:nums)
            if(it==1) one_cnt++;
        
        int ans=INT_MAX;
        int temp=0, last_temp=0;
        for(int i=nums.size()-one_cnt;i<nums.size();i++)
        {
            if(nums[i]==0) last_temp++;
        }
        
        for(int i=0;i<nums.size();i++) // i is ending point
        {
           if(i<one_cnt)
           {
               if(nums[i]==0) temp++;
               
               if(nums[nums.size()-one_cnt+i]==0) last_temp--;
                   
            ans=min(ans, temp+last_temp);
           }
            else
            {
               if(nums[i]==0) temp++;
               if(nums[i-one_cnt]==0) temp--;
                
                ans=min(ans, temp);
            }
        }
        
        return ans;                 
    }
};