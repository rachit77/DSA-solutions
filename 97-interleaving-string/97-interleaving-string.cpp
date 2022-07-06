class Solution {
public:
//     bool find_interleave(string &s1, int i,string s2, int j, string &res, string s3,unordered_map<string,int> &dp)
//     {
//         if(res.compare(s3)==0 && s1.length()==i &&j==s2.length()) return true;
        
//         bool ans=false;
        
//         int pos=res.length();
        
//         string key=to_string(i)+"*"+to_string(j);//+"*"+to_string(pos);
        
//         if(dp.find(key)!=dp.end()) return dp[key];
        
//         if(i<s1.length() && s3[pos]==s1[i])
//         {
//             res.push_back(s1[i]);
//             ans |= find_interleave(s1,i+1,s2,j,res,s3,dp); 
//             res.pop_back();
//         }
        
//         if(j<s2.length() && s3[pos]==s2[j])
//         {
//             res.push_back(s2[j]);
//             ans |= find_interleave(s1,i,s2,j+1,res,s3,dp); 
//             res.pop_back();
//         }
        
//         return dp[key]=ans;
//     }
    
    
    bool isInterleave(string s1, string s2, string s3) {
      
        if(s1.length() +s2.length() !=s3.length()) return false;
        
        // string res="";
        // int i=0,j=0;
        // unordered_map<string,int> dp;
        // return find_interleave(s1,i,s2,j,res,s3,dp);
        
        //method-2 tabulation sc:O(s1.len * s2.len)
        
        int s1_len=s1.length(), s2_len=s2.length();
        //make a dp
        bool dp[s1_len+1][s2_len+1];
        
        dp[0][0]=true;
        
        //fill the first row
        for(int j=1;j<s2_len+1;j++)
        {
            // bool temp= (s2[j-1]==s3[j-1]);
            dp[0][j]= (dp[0][j-1] && (s2[j-1]==s3[j-1]));
        }
        
        //fill the first column
        for(int i=1;i<s1_len+1;i++)
        {
           bool temp= (s1[i-1]==s3[i-1]);
            dp[i][0]=dp[i-1][0] && temp;
        }
    
        for(int i=1;i<s1_len+1;i++)
        {
            for(int j=1;j<s2_len+1;j++)
            {
                
                dp[i][j]=(dp[i-1][j] && (s1[i-1]==s3[i+j-1]))||(dp[i][j-1] && (s2[j-1]==s3[i+j-1]));
            }
        }
        
        return dp[s1_len][s2_len];
        
    }
};