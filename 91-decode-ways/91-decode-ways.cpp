class Solution {
public:
    //method-1 memmoization
//     int find(string s, int i, int dp[])
//     {
//         if(dp[i]!=-1) return dp[i];
        
//         if(i==s.length()) return 1;
        
//         int s1,s2;
//         int a=0,b=0;
        
//         s1=s[i]-'0';
//         if(s1!=0)
//         a=find(s,i+1,dp);      
        
//         if(i<s.length()-1 )
//            {
//                s2=s[i+1]-'0';
//             if(s1==1 || (s1==2 && s2<=6))
//                b=find(s,i+2,dp);
//            }
        
        
//         return dp[i]=a+b;
//     }
//     int numDecodings(string s) {
//         int dp[s.length()+1];
//         memset(dp,-1,sizeof(dp));
//         return find(s,0,dp);
        
//     }
    
    //method-2 tabulation
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,0);
        
       // dp[0]=1;
        
        int s1,s2;
        s1=s[0]-'0';
        if(s1!=0) dp[0]=1;
        //cout<<dp[1]<<endl;
        
        if(n>=1)
        {
            s2=s[1]-'0';
            if(s2!=0) dp[1]=dp[0];
            
            if(s1==1 || (s1==2 &&  s2<=6))
            {
              dp[1]+=1;
            }
                
        }
        
        for(int i=2;i<n;i++)
        {
            int a=0,b=0;
            s1=s[i]-'0';
            if(s1!=0) 
                a=dp[i-1];
            
            s2=s[i-1]-'0';
            if(s2==1 || (s2==2 && s1<=6))
            {
                b=dp[i-2];
            }
            dp[i]=a+b;
            
            // cout<<a<<" "<<b<<endl;
        }
        return dp[n-1];
    }
};