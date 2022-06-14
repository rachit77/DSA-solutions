class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        //method-1
        int n=nums.size();
        vector<int> v(nums.begin(),nums.end());
        
        sort(v.begin(),v.end());
        
        int a=0,b=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=v[i])
            {
                a=i;
                break;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]!=v[i])
            {
                b=i;
                break;
            }
        }
        
        if(a==b) return 0;
        return b-a+1;
        
        //approch-2
        // find first and last point of diff
        
//         int i,n=nums.size();
        
//         //find left point
//         int l_max=nums[0],st=0;
//         for(i=0;i<n;i++)
//         {
//             if(nums[i]>l_max)
//             {
//                 st=i;
//                 l_max=nums[i];
//             }
//             else if(l_max==nums[i]) continue;
//             else
//             {
//                 break;
//             }
//         }
//          cout<<st;
        
        
        
//         //
//         return 0;
    }
};