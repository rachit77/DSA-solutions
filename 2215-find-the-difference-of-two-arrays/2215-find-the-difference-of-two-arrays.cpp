class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       
        
        vector<vector<int>> ans(2);
        unordered_map<int,int> mp;
        
        for(int i:nums1)
        {
            mp[i]=1;
        }
        
        for(int i:nums2)
        {
            if(mp[i]==1 || mp[i]==3) mp[i]=3;
            else
                mp[i]=2;
        }
        
        for(auto it:mp)
        {
            //cout<<it.first<<" "<<it.second<<endl;
            if(it.second==1)
                ans[0].push_back(it.first);
            
            else if(it.second==2)
                ans[1].push_back(it.first);
        }
        
        return ans;
    }
};