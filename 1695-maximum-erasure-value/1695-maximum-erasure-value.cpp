class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> pre(n+1,0);
        
        for(int i=1;i<=n;i++)
            pre[i]=pre[i-1]+ nums[i-1];
        
        unordered_map<int,int> mp;  //num, index
        
        int sum_sub=0, cur_sum=0, st=0;
        for(int i=0;i<n;i++)
        {
           if(mp.count(nums[i])>0 && mp[nums[i]]>=st) // number already exist
           {
                   sum_sub=max(sum_sub, cur_sum);
                   cur_sum=pre[i+1]-pre[ mp[nums[i]] +1];
                    st=mp[nums[i]]+1;
                   
                    mp[nums[i]]=i;
           }
            else
            {
                cur_sum+=nums[i];
                mp[nums[i]]=i;
            }
            
        }
         sum_sub=max(sum_sub, cur_sum);
        
        return sum_sub; 
    }
};