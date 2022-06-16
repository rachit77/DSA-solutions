class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //binary search
        
        int l=0,h=nums.size()-1,ans=-1;
        
        while(l<=h)
        {
            int mid= l+(h-l)/2;
            
            if(nums[mid]==target)
               return mid;
            
           if(nums[l]<=nums[mid])  //left side is sorted
           {
               if(target<nums[mid] && target>=nums[l])
               {
                   h=mid-1;
               }
               else
                   l=mid+1;
           }
            else // the right side is sorted
            {
               if(target>= nums[mid] && target<=nums[h])
               {
                   l=mid+1;
               }
                else
                    h=mid-1;
            }
        }
        
        return ans;
        
    }
};