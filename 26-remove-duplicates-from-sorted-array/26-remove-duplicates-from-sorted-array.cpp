class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,n=nums.size(),idx=1,cnt=1,seen=-200;
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1] && nums[i+1]>seen) //junction
            {
                seen=nums[i+1];

                //swap
               int temp=nums[i+1];
                nums[i+1]=nums[idx];
                nums[idx]=temp;
                
                cnt++;
                idx++;
            }
        }
        return cnt;
    }
};