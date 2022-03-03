class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        vector<int> v;
        
        int dif=0,ans=0,temp=2;
        
        int len=nums.size();
        
        if(len>=3)
        {
            dif=nums[1]-nums[0];
            
            for(int i=1;i<len-1;i++)
            {
                int k=nums[i+1]-nums[i];
                
                if(k==dif)
                    temp++;
                else {
                    if(temp>=3)
                        v.push_back(temp);
                    
                    dif=k;
                    temp=2;
                }
            }
            
            if(temp>=3)
                v.push_back(temp);
            
        }
        
        for(int i=0;i<v.size();i++)
        {
            ans=ans+((v[i]-1)*(v[i]-2))/2;
        }
        
        
        return ans;
        
    }
};