class Solution {
public:
    
    struct compare {
        bool operator()(pair<int,int> const& a, pair<int,int> const& b){
            return a.second < b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // key->number.  value->frequency
        unordered_map<int,int> m;
        
        // store frequency of all element
        for(int i=0;i<nums.size();i++) {
            m[nums[i]]++;
        }
        
        //build a max heap
    priority_queue< pair<int,int>, vector<pair<int,int>>, compare>  heap;
        
        for(auto it: m) {
            heap.push(make_pair(it.first, it.second));
        }
        
        vector<int> ans; //store top-k elements
        
        while(k--) {
            pair<int,int> temp= heap.top();
            heap.pop();
            ans.push_back(temp.first);
        }
        
        return ans;
        
    }
};