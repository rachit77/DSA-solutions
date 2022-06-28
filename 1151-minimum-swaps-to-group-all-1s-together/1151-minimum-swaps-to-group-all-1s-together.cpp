class Solution {
public:
    int minSwaps(vector<int>& data) {
       
        int one_count=0;
        for(auto it: data)
            if(it==1) one_count++;
        
        int ans=INT_MAX;
        int temp=0;
        for(int i=0;i<data.size();i++)
        {
            if(i<one_count)
            {
                if(data[i]==0) temp++;   
            }
            else 
            {
                ans=min(ans,temp);
                if(data[i]==0) temp++;
                if(data[i-one_count]==0) temp--;
            }
        }
        ans=min(ans,temp);
        return ans;
    }
};