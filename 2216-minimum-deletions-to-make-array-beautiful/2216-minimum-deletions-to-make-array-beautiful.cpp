class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int del=0,flag=0;
        int n=nums.size();
       
        if(n==1) return 1;
        
        int l=0,r=1;
        
        while(r<n)
        {
          if(nums[l]==nums[r] && l%2==flag)
          {
              int temp=0;
              while(r<n && nums[l]==nums[r])
              {
                  temp++;
                  r++;
              }
              del+=temp;
              if(temp%2==1) flag=1-flag;
              l=r;
              r=r+1;
          }
         else
         {
            l++;
            r++;
         }
        }
        
        if((n-del)%2==1) del++;
        
        return del;
    }
};