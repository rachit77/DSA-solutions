class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans,v1,v2;
        
        for(int i=0;i<n;i++)
        {
          if(nums[i]>0)
              v1.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
        }
        
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
               ans.push_back(v1[a]) ;
                a++;
            }
            else
            {
                ans.push_back(v2[b]) ;
                b++;
            }
        }
        
        return ans;
    }
};