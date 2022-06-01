class Solution {
public:
    string longestPalindrome(string s) {
        
        // method-1 naive aproach tc=O(N^3)
        
        // method-2    dp approach sc:O(n^2)
//         int i,j,n=s.length();
//         int dp[n][n];    // st and end point of substring
//         memset(dp,0,sizeof(dp));
        
//         // if(s[st]== s[end]) dp[st][end]=1+ dp[st+1][end-1]
//         // fill substring of len 1 and 2
        
//         int len=1,st=0;
        
//         for(i=0;i<n;i++)
//             dp[i][i]=1;
        
//         for(i=0;i<n-1;i++)
//         {
//             if(s[i]==s[i+1])
//             {
//                 dp[i][i+1]=2;
//                 len=2;st=i;
//             }
//         }
        
        
//         for(i=3;i<=n;i++)  //i represent len of substr
//         {
//             for(j=0;j<n-(i-1);j++)  // j is startinh point
//             {
//                 // st=j and end= j+i-1
//                 if(s[j]==s[j+i-1] && dp[j+1][j+i-2]!=0) // st==end
//                 {
//                     dp[j][j+i-1]=i;
//                     if(i>len)
//                     {
//                         len=i;
//                         st=j;
//                     }
//                 }
//             }
//         }
        
//         return s.substr(st,len);
        
        
        //method-3 decreasing space complexity of method 2
        int i,j,n=s.length();
        
        int len=0,st=0;
        
        for(i=0;i<n;i++) //i is center point of palindrome substring
        {
            int temp_len=1;
            int temp_st=i;
            
           
        //considering odd length substring
            int l=i-1,h=i+1;
            while(l>=0 && h<n && s[l]==s[h])
            {
                temp_st=l;
                l--;
                h++; 
                temp_len+=2;
            }//while loop end
            
            if(temp_len>len)
            {
                len=temp_len;
                st=temp_st;
            }
            
            
            //even lebgth substring
            if(i>0 &&s[i]==s[i-1])
            {
                temp_len=2;
                temp_st=i-1;
                
                l=i-2;
                h=i+1;
                while(l>=0 && h<n && s[l]==s[h])
                {
                    temp_len +=2;
                    temp_st=l;
                    l--;
                    h++;
                }
                
                if(temp_len > len)
                {
                    len=temp_len;
                    st=temp_st;
                }
            }
            
        }
        
        return s.substr(st,len);
        
    }
};