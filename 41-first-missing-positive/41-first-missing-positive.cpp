class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==i+1) continue;
 
            if(nums[i]>0) {
                int correctPos= nums[i]-1;
                
                
     while(nums[i]>=1 && nums[i]<=nums.size() && nums[i]!=nums[correctPos])
                {
                    
                    //swap val present at pos i and correctPos
                    int temp=nums[i];
                    nums[i]=nums[correctPos];
                    nums[correctPos]=temp;
                    
                      correctPos= nums[i]-1;
                }
        }
                
            
        }
        
        
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
        
        
        
      
        
    }
};