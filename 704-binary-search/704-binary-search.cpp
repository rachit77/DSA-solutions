class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        int l=0,h=nums.size()-1,ans=-1;
       
        while(l<=h)
        {
            
            int mid= l+(h-l)/2;
                
                if(nums[mid]==target) 
                {
                    ans=mid;
                    break;
                }
            else if(target<nums[mid])
                h=mid-1;
            else
                l=mid+1; 
            
            
        }
        
        return ans;
    }
};