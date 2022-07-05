class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        //method-1
//         int n=nums.size();
//         vector<int> ans,v1,v2;
        
//         for(int i=0;i<n;i++)
//         {
//           if(nums[i]>0)
//               v1.push_back(nums[i]);
//             else
//                 v2.push_back(nums[i]);
//         }
        
//         int a=0,b=0;
//         for(int i=0;i<n;i++)
//         {
//             if(i%2==0)
//             {
//                ans.push_back(v1[a]) ;
//                 a++;
//             }
//             else
//             {
//                 ans.push_back(v2[b]) ;
//                 b++;
//             }
//         }
        
//         return ans;
        
        //method-2
        int n=nums.size();
        vector<int> ans(n);
        
        int pos=0,neg=1;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[pos]=nums[i];
                pos+=2;
            }
            else
            {
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        
        return ans;
        
    }
};