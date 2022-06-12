class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //method-1 sort
        //method-2 count the number of occurence
        
        // method-3 two pointers 
        int n=nums.size();
        int l=0,h=n-1,mid=0;
        
        while(mid<=h)
        {
            //3  cases
            
            if(nums[mid]==0)
            {
                //swap l and mid
                nums[mid]=nums[l];
                nums[l]=0;
                l++;
                mid++;
            }
            else if(nums[mid]==1)
            {
               mid++; 
            }
            else //nums[mid]==2
            {
                //swap h and mid
                nums[mid]=nums[h];
                nums[h]=2;
                h--;
            }
        }
        
    }
};