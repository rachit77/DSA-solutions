class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int sum=0,num_min=INT_MAX;
        for(int it:nums)
        {
            sum+=it;
            num_min=min(num_min,it);
        }
        
        return sum-(num_min*nums.size());
    }
};