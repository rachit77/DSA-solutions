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


// st=3
    
//     0. 3
//     1. 2
//     3 0
//     4 2
//     5 2
//     6. 1
//     7. 2
//     8 3
//     9. 4
//     10 3
    