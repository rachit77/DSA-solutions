class Solution {
public:
    void find(int i, int o, int c,int n,string s, vector<string> &ans)
    {
        if(c>o || o>n || c>n) return;
        
        if(o==c && o==n) 
        {
            ans.push_back(s);
            return;
        }
        
        find(i+1,o+1,c,n,s+"(",ans);
        find(i+1,o,c+1,n,s+")",ans);
            
        return;    
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string s;
        find(0,0,0,n,s,ans);
        return ans;
        
    }
};