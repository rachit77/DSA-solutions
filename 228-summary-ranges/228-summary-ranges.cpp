class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> s;        
        int n=nums.size();
        if(n==0)
            return s;
        
        int st=nums[0];
        
        for(int i=0;i<n;i++)
        {
            if(i == n-1 || nums[i+1]!=nums[i]+1  )
            {
                if(st!=nums[i])  
                    s.push_back(to_string(st) +"->"+to_string(nums[i]));
                  
                    
                    
                else
                    s.push_back(to_string(st));
                  
                
                    
                if(i!=n-1)
                st=nums[i+1];
                
            }
            
            
        }
        
        
        
        return s;
        
        
        
    }
};