class Solution {
public:
    
    bool check(vector<int>& nums, int m, int mid)
    {
        int temp=0,count=1;
        
        for(int i:nums)
        {
            temp+=i;
            if(temp>mid)
            {
                count++;
                temp=i;
            }
            
            if(count>m) return false;
        }
        
       return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int start=INT_MIN;
        int end=0;
        
        for(int i:nums)
        {
            start=max(start,i);
            end+=i;
        }
        
        int mid,ans;
        
        while(start <= end)
        {
            mid=start + (end-start)/2;
            
            if( check(nums,m,mid))
            {
                end=mid-1;
                ans=mid;
            }
            else 
                start=mid+1;
        }
        return ans;
    }
};
