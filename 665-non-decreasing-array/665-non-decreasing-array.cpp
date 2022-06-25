class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int count=0,idx=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                count++;
                idx=i;
            }
        }
        cout<<count<<endl;
        if(count>1) return false;
        
        if(count==0) return true;
        
        if(count==1 && (idx==0|| idx==nums.size()-2)) return true;
      
        //cout<<nums[idx];
        return (nums[idx]<=nums[idx+2] || nums[idx-1]<=nums[idx+1]);
    }
};