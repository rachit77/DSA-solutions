class Solution {
public:
    int lcs(int i,string &s1,int j, string &s2, vector<vector<int>> &dp)
    {
        int n=s1.length();
        int m=s2.length();
        
        if(i>=n || j>=m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int temp1,temp2;
        if(s1[i]==s2[j])
        {
         temp1=1+ lcs(i+1,s1,j+1,s2,dp);   
        }
        else
        {
            temp1= lcs(i+1,s1,j,s2,dp);
            temp2=lcs(i,s1,j+1,s2,dp);
            temp1=max(temp1,temp2);
        }
        
        return dp[i][j]=temp1;
    }
    
    int minDistance(string word1, string word2) {
        // aproach: find LCS of these 2 strings
        int n=word1.length(), m=word2.length(),l,ans;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        // l: lcs len
        //ans=n-l + m-l ;
        
        l= lcs(0,word1,0,word2,dp);
      
        return n+m-2*l;
        
    }
};