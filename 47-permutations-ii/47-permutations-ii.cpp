class Solution {
public:
    
    // APPROACH 1 : C ORRECT BUT MEMORY LIMIT EXCEEDED
//     vector<vector<int>> ans;
    
//     void find(map<int,int> m, int count, vector<int> v, int n)
//     {
//         if(count == n) {
//             ans.push_back(v);
//             return;
//         }
        
//         for(auto i:m) {
//             if(i.second !=0)
//             {
//                 v.push_back(i.first);
//                 i.second--;
                
//                 find(m, count++,v,n);
//             }
//         }
//         return;
//     }
    
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
        
//         //make a hash map
//         map<int,int> m;
        
//         for(auto x:nums) 
//             m[x]++;
        
//         vector<int> v;
//         int n=nums.size();
        
//         find(m,0,v,n);
        
//         return ans;
//     }

//vector<vector<int>> ans;
    set<vector<int>> ans;
    
    void permutate(vector<int> nums, int idx)
    { 
      if(idx==nums.size())
      {
          //ans.push_back(nums);
          ans.insert(nums);
          return;
      }
        
        for(int i=idx;i<nums.size();i++) {
            
            if(i!=idx && nums[i] == nums[idx]) 
                continue;
                
            swap(nums[i],nums[idx]);
            permutate(nums, idx+1);
        }
        return;
    }

vector<vector<int>> permuteUnique(vector<int>& nums) {
   // sort(nums.begin(), nums.end());
    permutate(nums,0);
    
    vector<vector<int>> ans1;
    
    for(auto x: ans)
        ans1.push_back(x);
    
    return ans1;
   }
};