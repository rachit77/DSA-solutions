class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        //method-1 nlogn
//         int n=nums.size();
//         vector<int> v(nums.begin(),nums.end());
        
//         sort(v.begin(),v.end());
        
//         int a=0,b=0;
        
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]!=v[i])
//             {
//                 a=i;
//                 break;
//             }
//         }
        
//         for(int i=n-1;i>=0;i--)
//         {
//             if(nums[i]!=v[i])
//             {
//                 b=i;
//                 break;
//             }
//         }
        
//         if(a==b) return 0;
//         return b-a+1;
        
        //method-2 TC: O(N)
        int n=nums.size(),i;
        int l=0,h=n-1;
        
        while(l<n-1 && nums[l]<=nums[l+1]) l++;
        while(h>0 && nums[h]>=nums[h-1]) h--;
        
        if(l==n-1) return 0;
        
        int arr_min=INT_MAX, arr_max=INT_MIN;
        
        for(int i=l;i<=h;i++)
        {
            arr_min=min(arr_min,nums[i]);
            arr_max=max(arr_max,nums[i]);
        }
        
        while(l-1>=0 && nums[l-1] > arr_min) l--;
        while(h+1<n && nums[h+1]<arr_max) h++;
        
        return h-l+1;
    }
};