class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
 
        //method-1
//         int n=nums.size();
//         vector<int> pre(n+1,0);
        
//         for(int i=1;i<=n;i++)
//             pre[i]=pre[i-1]+ nums[i-1];
        
//         unordered_map<int,int> mp;  //num, index
        
//         int sum_sub=0, cur_sum=0, st=0;
//         for(int i=0;i<n;i++)
//         {
//            if(mp.count(nums[i])>0 && mp[nums[i]]>=st) // number already exist
//            {
//                    sum_sub=max(sum_sub, cur_sum);
//                    cur_sum=pre[i+1]-pre[ mp[nums[i]] +1];
//                     st=mp[nums[i]]+1;
                   
//                     mp[nums[i]]=i;
//            }
//             else
//             {
//                 cur_sum+=nums[i];
//                 mp[nums[i]]=i;
//             }
            
//         }
//          sum_sub=max(sum_sub, cur_sum);
        
//         return sum_sub; 
        
        //method-2 sliding window and freq vector
        int n=nums.size();
        vector<int> freq(10001,0);
        
        int j=0,i=0,cur_sum=0,ans=0;
        
        while(j<n)
        {
            if(freq[nums[j]]) //num already present
            {
                ans=max(ans,cur_sum);
                while(freq[nums[j]])
                {
                    cur_sum -= nums[i];
                    freq[nums[i]]--;
                    i++;
                }
                
            }  
                freq[nums[j]]++;
                cur_sum+=nums[j];
                
                j++;
              
        }
        
        ans=max(ans,cur_sum);
        return ans;
    }
};