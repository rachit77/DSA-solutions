class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        long long sum=0;
        for(auto it:nums)
            sum+=it;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=LONG_MAX;
        
        for(int i=0;i<n;i++) // i is pt of convergence
        {
            long long temp=(long long)nums[i]* (n-i);
            temp=sum-temp;
            ans=min(ans,temp);
        }
        
        return ans;
    }
};