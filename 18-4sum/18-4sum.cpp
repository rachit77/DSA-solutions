class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {       
            for(int j=i+1;j<n;j++)
            {  
                
                int new_tar= target-nums[i]-nums[j];
                
                int lo=j+1,hi=n-1;
                
                while(lo<hi)
                {
                    if(nums[lo]+nums[hi]==new_tar)
                    {
                        vector<int> temp(4);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[lo];
                        temp[3]=nums[hi];
                        ans.push_back(temp);
                        
                        while(lo<hi && nums[lo]==nums[lo+1])
                        {
                            lo++;
                        }
                        
                        while(lo<hi && nums[hi]==nums[hi-1])
                        {
                            hi--;
                        }
                        
                        lo++;
                        hi--;
                        
                    }
                    else if(nums[lo]+nums[hi]>new_tar)
                    {
                        hi--;
                    }
                    else
                        lo++;
                }
                
                 //move j
            while(j+1<n && nums[j]==nums[j+1]) j++;
                
            }
            
            //move i
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        
        return ans;
        
    }
};