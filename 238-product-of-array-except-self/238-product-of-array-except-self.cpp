class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        //method-1 brute force o(N^2)
        
        //method- prefix and suffix product 
        
        //method-3 contant space
        long long prd=1;
        int n=nums.size();
        vector<int> ans(n,1);
        
        for(int i=0;i<n;i++)
        {
           ans[i]=prd;
           prd=prd*nums[i];
          
        }
        
       // for(auto it:ans) cout<<it<<endl;
        prd=1;
        
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=ans[i]*prd;
            prd*=nums[i];
        }
        
        return ans;
    }
};