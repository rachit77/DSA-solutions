class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> s;
//         int ans=0;
//         for(int i=0;i<nums.size();i++)
//             s.insert(nums[i]);
        
//         for(int i=0;i<nums.size();i++)
//         {
//             if(s.find(nums[i]-1) == s.end()) //nums[i] is smallest //of that seq
//             {
//                 int j= nums[i]+1,count=1;
//                     while(s.find(j)!=s.end())
//                     {
//                         j++;
//                         count++;
                        
//                     }
//                 ans =max(ans,count);
//             }
//         }
//        return ans;       
        
//     }
        
     //method-2 sorting
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int max_streak=0;
        int cur_streak=1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==nums[i]) continue;
             if(nums[i-1]+1==nums[i])
             {
                 cur_streak+=1;
             }
            else
            {
                max_streak=max(cur_streak,max_streak);
                cur_streak=1;
            }
        }
        
        return max(cur_streak,max_streak);
    }
};