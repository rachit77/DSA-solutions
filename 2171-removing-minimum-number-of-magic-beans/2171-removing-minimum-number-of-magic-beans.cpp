class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        long long sum=0,cur_sum=0;
        for(auto it:nums)
            sum+=it;
        
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        long long ans=LONG_MAX;
        for(int i=0;i<n;i++) // i is pt of convergence
        {
            long long temp=nums[i]*(n-i);
            temp=sum-temp+cur_sum;
            ans=min(ans,temp);
            //sum-=nums[i];
            //cur_sum+=nums[i];
            //cout<<temp<<endl;
        }
        
        return ans;
    }
};