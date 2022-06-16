class Solution {
public:
    long long find(long long mid,vector<int>& time)
    {
        long long ans=0;
        for(int i=0;i<time.size();i++)
        {
            ans+= (mid/time[i]);
        }
        
        return ans;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        // max time taken to complete the task is 10^7 * 10^7
        long long l=1,h=1e14,ans=h;
        
        while(l<=h)
        {
            long long mid=l+(h-l)/2;    
             long long trips= find(mid,time);
            
            if(trips>=totalTrips)
            {
                h=mid-1;
                ans=min(ans,mid);
            }
            else
            {
                l=mid+1;
            }
                
        }
        
        return ans;
    }
};