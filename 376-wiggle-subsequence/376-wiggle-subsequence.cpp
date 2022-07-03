class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
       
        int flag=-1; //1=>prev +ve || 0=>prev -ve
        int cnt=1;
        
    
        
        for(int i=0;i<nums.size()-1;i++)
        {
            int dif=nums[i+1]-nums[i];
            if(dif>0 && flag==0)
                cnt++;
            else if(dif<0 && flag==1)
                cnt++;
            
            if(dif>0) flag=1;
            else if(dif<0) flag=0;
        }
        if(flag!=-1) cnt++;
        return cnt;
    }
};