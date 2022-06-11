class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
       sort(nums.begin(), nums.end());
        int ans,dif=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            int l=i+1,r=nums.size()-1;
            
            while(l<r)
            {
                int cur_sum=nums[i]+nums[l]+nums[r];
                if(cur_sum==target) return cur_sum;
                if(abs(target-cur_sum)<dif)
                {
                    dif=abs(target-cur_sum);
                    ans=cur_sum;
                }
                
                if(cur_sum < target) l++;
                else
                    r--; 
            }
        }
        return ans;
        
    }
};