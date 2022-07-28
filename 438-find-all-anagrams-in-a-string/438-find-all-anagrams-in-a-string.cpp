class Solution {
public:
    bool check(vector<int> &p,string &s, int st, int &m)
    {
        vector<int> temp(26,0);
        
        for(int i=0;i<m;i++)
        {
            temp[s[i+st]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(p[i]!=temp[i]) return false;
        }
        
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        // rabin karp - rolling hash
        int n=s.length(),m=p.length();
        
        vector<int> ans;
        if(n<m) return ans;
        int cur_hash=0,p_hash=0;
        
        vector<int> pcount(26,0);
        //cal starting hash
        for(int i=0;i<m;i++)
        {
            pcount[p[i]-'a']++;
            cur_hash+=(s[i]-'a');
            p_hash+= (p[i]-'a');
        }
        
        if(cur_hash==p_hash)
        {
            if(check(pcount,s,0,m)) ans.push_back(0);
        }
            
        
        for(int i=m;i<n;i++)
        {
            cur_hash= cur_hash + (s[i]-'a') -(s[i-m]-'a');
            if(cur_hash==p_hash)
            {
                if(check(pcount,s,i-m+1,m)) ans.push_back(i-m+1);
            }
        }
        
        return ans;
    }
};