class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // // method-1 sort the array TC: Nlog(N)
        // sort(nums.begin(),nums.end(), greater<int>());
        // return nums[k-1];
        
        //method-2 using priority queue
        priority_queue <int, vector<int>, greater<int>> pq; //min heap
        for (auto i : nums) {
            if (pq.size() != k || i > pq.top()) {
                if (pq.size() == k)
                    pq.pop();
                pq.push(i);
            }
        }
        return pq.top();
        
    }
};