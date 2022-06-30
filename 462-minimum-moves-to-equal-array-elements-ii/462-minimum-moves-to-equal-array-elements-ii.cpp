class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        //find median of all elements
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2];
        
        int ans=0;
        for(int it:nums)
        {
            ans+=abs(it-median);
        }
        
        return ans;
    }
};