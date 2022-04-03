class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i,n=nums.size();
       int break_pt=-1;
           
           //find break pt
           for(i=n-1;i>0;i--)
           {
               if(nums[i-1]<nums[i])
               {
                   break_pt=i-1;
                   break;
               }
           }
        
        //no break pt
        if(break_pt==-1)
        {
            reverse(nums.begin(),nums.end());
           return;
        }
        
        for(i=n-1;i>=0;i--)
        {
            if(nums[i]> nums[break_pt])
            {
                //swp the elements
                swap(nums[i],nums[break_pt]);
                reverse(nums.begin() +break_pt+1,nums.end());
                break;      
            }
        }
     
    }
   
};