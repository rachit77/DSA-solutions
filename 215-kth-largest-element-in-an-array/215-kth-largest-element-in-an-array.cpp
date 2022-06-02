class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // method-1 sort the array
        sort(nums.begin(),nums.end(), greater<int>());

        return nums[k-1];
        
    }
};