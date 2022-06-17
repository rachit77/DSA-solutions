class Solution {
public:
    int find(vector<int>& nums,int l, int h,int n)
    {
        int m=l+(h-l)/2;
        
        if((m==0 || nums[m-1]<= nums[m]) &&(m==n-1 || nums[m+1]<= nums[m]))
        {
            return m;
        }
        
        else if(m>0 && nums[m-1]>nums[m])
        {
            return find(nums,l,m-1,n);
        }
        else
        {
            return find(nums,m+1,h,n);
        }
    }
    int findPeakElement(vector<int>& nums) {
        
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     if (nums[i] > nums[i + 1])
        //         return i;
        // }
        // return nums.size() - 1;
        int n=nums.size();
        return find(nums,0,n-1,n);
    }
};