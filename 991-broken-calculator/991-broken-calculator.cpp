class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        
        int ans=0;
        
        while(target>startValue)
        {
            if(target%2==0)
            {
                ans++;
                target=target/2;
            }
                
            else {
                ans=ans+2;
                target=(target+1)/2;
            }
        }
        //cout<<ans<<endl;
        
        ans=ans+ startValue-target;
        
        return ans;
        
    }
};

    