class Solution {
public:
    
    unordered_map<string,int> dp;
    
    int solve(string s,vector<string> &b ) {
        
        int siz=s.length();
        if(siz==0) return 1;
        
        if(dp[s]!=0)  // string already present in dp
            return dp[s];
        
        for(int i=1;i<=siz;i++)  // make the string to be searched
        {
            string ss=s.substr(0,i);
            int f=0;
            
           
            
            for(int j=0;j<b.size();j++)
            {
                if(ss==b[j]) // we got the string in dict
                {
                    f=1;
                    dp[ss]=1;
                    break;
                }
                
            }
            
                if(f==1 && (solve(s.substr(i,siz-i),b)==1)){
                   return dp[s]=1;
                
            } 
        }
        return dp[s]=-1;
        
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int x= solve(s,wordDict);
        if(x==1)
            return 1;
        else
            return 0;
        
    }
};