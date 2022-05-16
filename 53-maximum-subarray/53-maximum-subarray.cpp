class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum=INT_MIN,cur=0;
        
        for(int i =0;i<nums.size();i++) {
            
            if(nums[i] > cur+nums[i])  // discard prev arr
            {
        
                cur=nums[i];
            }
            else {
                cur+=nums[i];
            }
            
            sum=max(sum,cur);
        }
        
        return sum;
        
    }
};    