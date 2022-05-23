class Solution {
public:
   int dp[601][101][101];
    //int dp[601][101][101]={{{-1}}};
    int check( vector<pair<int,int>>& v,int i, int m, int n)
    {
        if(i==v.size()) return 0; //base case
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        
        int ans=0;
        
        if(m-v[i].first>=0 && n-v[i].second>=0)
        {
            //2 case include and not includ i
           ans=max(ans, 1+ check(v,i+1,m-v[i].first,n-v[i].second));
            ans=max(ans, check(v,i+1,m,n));
        }
        else
        {
            // not include i since it is out of bounds
           ans=max(ans, check(v,i+1,m,n));
        }
        
        return dp[i][m][n]=ans;
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int ans=0,i,j,s=strs.size();
        vector<pair<int,int>> v;
        
        for(i=0;i<s;i++)
        {
            int x=0,y=0;
            for(j=0;j<strs[i].length();j++)
            {
                if(strs[i][j]=='0') x++;
                else y++;
            }
            v.emplace_back(make_pair(x,y));
        }
        
        memset(dp,-1,sizeof(dp));
       
        ans=check(v,0,m,n);
        return ans;
      
    }
};