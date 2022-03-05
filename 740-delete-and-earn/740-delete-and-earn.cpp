class Solution {
public:
    
    
    
    int deleteAndEarn(vector<int>& nums) {
        
      vector<int> dp(10001,0);
        
        // find freq and max element in nums
        vector<int> freq(10001,0);
        int ma=0;
        
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
            ma = max(ma, nums[i]);
        }
        
        dp[1]=1*freq[1];
        dp[0]=0;
        
        for(int i=2;i<=ma;i++)
        {
            dp[i]=max(dp[i-2]+i*freq[i], dp[i-1]);
        }
        
        return dp[ma];
        
    }
};