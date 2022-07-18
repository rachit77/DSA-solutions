class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
        // method1 brute force 
        
        // method-2 hash map
        unordered_map<int,int> mp;
        int  cur_sum=0 ,ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            cur_sum+=nums[i];
           
            int target=cur_sum-k;
            
            ans+=mp[target];
            
             mp[cur_sum]++;
        }
        return ans;
    }
};