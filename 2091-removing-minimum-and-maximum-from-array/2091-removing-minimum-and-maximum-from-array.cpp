class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        
        int num_min=INT_MAX, num_max=INT_MIN,a,b;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<num_min)
            {
                num_min=nums[i];
                a=i;
            }
            
            if(nums[i]>num_max)
            {
                num_max=nums[i];
                b=i;
            }
        }
        
        int p1=max(a,b)+1;
        int p2=n-(min(a,b));
        
        int a_flag=1,b_flag=1;
        if(a>=n/2)
        {
            a=n-a-1;
            a_flag=0;
        }
        
        if(b>=n/2)
        {
            b=n-b-1;
            b_flag=0;
        }
        int p3=a+b+2;
            
        return min(p3,min(p1,p2));
//         if(a_flag!=b_flag) return a+b+2;
//         else
//         return max(a,b)+1;
    }
};