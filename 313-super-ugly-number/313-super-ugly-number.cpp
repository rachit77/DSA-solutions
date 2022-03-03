class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
//        int len=primes.size();
        
//         vector<int> v(len,0);  
        
//         vector<int> dp(n,0);
//         dp[0]=1;
        
//         for(int i=1;i<n;i++)
//         {
//            int temp= INT_MAX;
//             for(int j=0;j<len;j++)
//             {
//                 temp=min(temp, primes[j]* dp[v[j]]);
//             }
            
//             dp[i]=temp;
            
//             for(int j=0;j<len;j++)
//             {
//                 if(dp[i]==   primes[j]* dp[v[j]] ) 
//                 {
//                     v[j]++;
                    
//                 }
//             }
//             // cout<<i<<" "<<dp[i]<<endl;
//         }
        
//         return dp[n-1];
        
        
        vector<int> dp(n+1,0); int k=primes.size();
   // memset(dp,0,sizeof(dp));
    dp[0]=1;
    vector<int> pointer(k,0);
    //memset(pointer,0,sizeof(pointer));
    for(int i=1; i<n; i++){
        int mn=INT_MAX;
        for(int j=0; j<k; j++){
            mn=min(primes[j]*dp[pointer[j]],mn);
        }
        dp[i]=mn;
        for(int j=0; j<k; j++){
            if(primes[j]*dp[pointer[j]]==mn){
                pointer[j]++;
            }
        }
    }
    return dp[n-1];
        
    }
};