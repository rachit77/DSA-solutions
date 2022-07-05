class Solution {
public:
    bool find_interleave(string &s1, int i,string s2, int j, string &res, string s3,unordered_map<string,int> &dp)
    {
        if(res.compare(s3)==0 && s1.length()==i &&j==s2.length()) return true;
        
        bool ans=false;
        
        int pos=res.length();
        
        string key=to_string(i)+"*"+to_string(j);//+"*"+to_string(pos);
        
        if(dp.find(key)!=dp.end()) return dp[key];
        
        if(i<s1.length() && s3[pos]==s1[i])
        {
            res.push_back(s1[i]);
            ans |= find_interleave(s1,i+1,s2,j,res,s3,dp); 
            res.pop_back();
        }
        
        if(j<s2.length() && s3[pos]==s2[j])
        {
            res.push_back(s2[j]);
            ans |= find_interleave(s1,i,s2,j+1,res,s3,dp); 
            res.pop_back();
        }
        
        return dp[key]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
      
        if(s1.length() +s2.length() !=s3.length()) return false;
        
        string res="";
        int i=0,j=0;
        unordered_map<string,int> dp;
        return find_interleave(s1,i,s2,j,res,s3,dp);
        
    }
};