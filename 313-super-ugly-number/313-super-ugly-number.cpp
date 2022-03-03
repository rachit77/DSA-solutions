class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
//          vector<int> dp(n+1,0); int k=primes.size();
//          dp[0]=1;
//         vector<int> pointer(k,0);   
//         for(int i=1;i<n;i++)
//         {
//            int mn= INT_MAX;
//             for(int j=0;j<k;j++)
//             {
//                 mn=min(primes[j]* dp[pointer[j]], mn);
//             }
            
//             dp[i]=mn;
//             for(int j=0;j<k;j++)
//             {
//                 if(primes[j]* dp[pointer[j]] ==mn) 
//                     pointer[j]++;   
//             }  
//         }
        
//         return dp[n-1];
        
        
        vector<int> dp(n,0); int k=primes.size();
   
    dp[0]=1;
    vector<int> pointer(k,0);
    
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