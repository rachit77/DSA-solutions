class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
 //write solution but tle : n^2 *log(m)       
//         unordered_map<int,int> m;
        
//         int i,n,j;
//         n=nums.size();
        
//         for(i=0;i<n;i++) {
//             m[nums[i]]++;
//         }
        
//         set<vector<int>> s;
        
//         for(i=0;i<n-1;i++)
//         {
//             m[nums[i]]--;
            
//             for(j=i+1;j<n;j++) {
//                 m[nums[j]]--;
                
//                 int sum =nums[i]+nums[j];
                
//                 int find= sum* -1;
                
//                 if(m[find]!=0) // got that element
//                 {
//                    //add items in vector
//                     //sort the vector
//                     //add vector in set 
//                     vector<int> v(3,0);
//                     v[0]=nums[i];
//                     v[1]=nums[j];
//                     v[2]=find;
                    
//                     sort(v.begin(), v.end());
                    
//                     s.insert(v);
//                 }
                
//                 m[nums[j]]++;
                
//             }
            
//             m[nums[i]]++;
            
            
//         }
        
//         vector<vector<int>> ans;
        
        
//         for(auto x:s)
//         {
//             ans.push_back(x);
//         }
        
//         return ans;
        
        
        
        // 2nd solution
        // 2 pointer based solution
        
        int i;
        
        int n=nums.size();
        vector<vector<int>> ans;
        
        if(n<3) return ans;
        
        sort(nums.begin(),nums.end());
        
        
        for(i=0;i<n-2;i++) {
            
            if(i==0 || nums[i]!=nums[i-1]) {
                int lo=i+1, hi=n-1,sum=0-nums[i];
                
                while(lo<hi) {
                    if(nums[lo]+nums[hi]==sum) {
                        
                        vector<int> v(3,0);
                        v[0]=nums[i];
                        v[1]=nums[lo];
                        v[2]=nums[hi];
                        
                        ans.push_back(v);
                        
                        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                        lo++;
                        hi--;
                        
                    }
                    else if(nums[lo]+nums[hi]<sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        
        return ans;

    }
};