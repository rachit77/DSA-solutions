class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
       
        unordered_map<int, int> countMap;
        vector<int> res;
        int desiredCount = nums.size();
        for(auto num : nums) {
            for(int i : num) {
                countMap[i]++;
                if(countMap[i] == desiredCount) {
                    res.push_back(i);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};