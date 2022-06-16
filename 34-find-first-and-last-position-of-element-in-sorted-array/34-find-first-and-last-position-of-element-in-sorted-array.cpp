class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        //binary search
        
        int l=0,h=nums.size()-1,ans=-1;
        
        while(l<=h)
        {
            int mid =l+(h-l)/2;
            
            if(nums[mid]==target)
            {
                ans=mid;
                break;
            }
            
            if(target<nums[mid])
                h=mid-1;
            else
                l=mid+1;
        }
        
        vector<int> res(2,-1);
        //cout<<ans;
        if(ans!=-1)
        {
            int a=ans,b=ans;
            
            while(a>=1 && nums[a-1]==nums[ans]) a--;
            while(b< nums.size()-1 && nums[b+1]==nums[ans]) b++;
            
            res[0]=a;
            res[1]=b;
        }
        
        return res;
    }
};