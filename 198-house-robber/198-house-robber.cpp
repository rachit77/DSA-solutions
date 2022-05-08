class Solution {
 
//1. Recursive approach 
// private:
//     int maxsum(vector<int>& nums,int id)
//     {
//         if(id>=nums.size()) return 0;
        
//         return max(nums[id]+maxsum(nums,id+2),maxsum(nums,id+1));
//     }
// public:
//     int rob(vector<int>& nums) {
//         return maxsum(nums,0);
//     }
 
    
    // 2. Memoization approach
//     private:
//     int maxsum(vector<int> &nums, int id, vector<int> &dp)
//     {
//         if(id>=nums.size()) return 0;
        
//         if(dp[id]!=-1)
//             return dp[id];
        
//         return dp[id]=max(nums[id]+maxsum(nums,id+2,dp), maxsum(nums,id+1,dp));
//     }
//     public:
//     int rob(vector<int>& nums) {
        
//         vector<int> dp(nums.size(),-1);
        
//         return maxsum(nums,0,dp);
        
//     }

    
    // 3. Top Down Aproach
    public:
    int rob(vector<int>& nums) {
        
       // vector<int> dp(nums.size(),0);
        
        int n=nums.size();
        
        int ne,prev;
        
        if(n==1)
        return nums[0];
        
        prev=nums[0];
        
        
        
        if(n>=2)
        ne= max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++)
        {
            int temp=ne;
            ne= max(ne, prev+nums[i]);
            prev=temp;
        }
        
        return ne;
        
    }
};