class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1) == s.end()) //nums[i] is smallest //of that seq
            {
                int j= nums[i]+1,count=1;
                    while(s.find(j)!=s.end())
                    {
                        j++;
                        count++;
                        
                    }
                ans =max(ans,count);
            }
        }
       return ans;       
        
    }
};