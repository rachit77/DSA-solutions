class WordFilter {
    
private:
    unordered_map<string,int> mp;
public:
    WordFilter(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
        {
            int n=words[i].size();
            // add all the prefix in the map 
            for(int j=1;j<=n;j++)
            {
                string pre=words[i].substr(0,j);
                //find all sufix 
                for(int k=0;k<n;k++) // k => starting index
                {
                    string suf= words[i].substr(k,n);
                    mp[pre+"#"+suf]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
       return mp[prefix+"#"+suffix]-1;
    }
    
   
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */