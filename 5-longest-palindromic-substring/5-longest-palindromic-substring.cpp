class Solution {
public:
    string longestPalindrome(string s) {
        
        // method-1 naive aproach tc=O(N^3)
        
        // method-2    dp approach sc:O(n^2)
        int i,j,n=s.length();
        int dp[n][n];    // st and end point of substring
        memset(dp,0,sizeof(dp));
        
        // if(s[st]== s[end]) dp[st][end]=1+ dp[st+1][end-1]
        // fill substring of len 1 and 2
        
        int len=1,st=0;
        
        for(i=0;i<n;i++)
            dp[i][i]=1;
        
        for(i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=2;
                len=2;st=i;
            }
        }
        
        
        for(i=3;i<=n;i++)  //i represent len of substr
        {
            for(j=0;j<n-(i-1);j++)  // j is startinh point
            {
                // st=j and end= j+i-1
                if(s[j]==s[j+i-1] && dp[j+1][j+i-2]!=0) // st==end
                {
                    dp[j][j+i-1]=i;
                    if(i>len)
                    {
                        len=i;
                        st=j;
                    }
                }
            }
        }
        
        return s.substr(st,len);
        
    }
};