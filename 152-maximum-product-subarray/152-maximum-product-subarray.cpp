class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();

// correct solution but TLE , O(n^2)       
        
//         int prd=INT_MIN;
        
//         for(int i=0;i<n;i++) {
//             int prev=1;
//             for(int j=i;j<n;j++) 
//             {
//                 prev=prev*nums[j];
                
//                 prd=max(prd,prev);
//             }
//         }
        
//         return prd;
        
//2nd solution
int ma=nums[0],mi=nums[0],ans=nums[0];
        
        for(int i=1;i<n;i++) {
            
            if(nums[i]<0)
            {
                swap(ma,mi);
            }
            
            ma=max(nums[i],ma*nums[i]);
            
            mi= min(nums[i],mi*nums[i]);
            
            ans=max(ans,ma);
            
        }
        
        return ans;
        
    }
};