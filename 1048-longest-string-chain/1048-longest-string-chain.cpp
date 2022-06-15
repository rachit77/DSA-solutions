class Solution {
public:
   
    //method-1
    bool static comp(const string &a, const string &b)
    {
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(),comp);
        
        unordered_map<string,int> mp;
        for(auto x: words)
            mp[x]=1;
        int ans=1;
        for(string word: words)
        {
            for(int i=0;i<word.length();i++)
            {
                string prev=word.substr(0,i)+word.substr(i+1);
                if(mp.find(prev)!=mp.end())
                {
                    mp[word]=max(mp[word], mp[prev]+1);
                    ans=max(ans,mp[word]);
                }
            }
        }
    
        return ans;
    }
};