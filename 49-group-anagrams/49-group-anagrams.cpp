class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map< vector<int>, vector<string> > mp;
        vector< vector<string>> ans;
        
        for(int i=0;i<strs.size();i++)
        {
            vector<int> count(26,0);
            for(int j=0;j<strs[i].length();j++)
            {
                count[strs[i][j]-'a']++;
            }
            
            mp[count].push_back(strs[i]);
        }
        
        for(auto x: mp)
        {
           //cout<<x.second.size(); 
            ans.push_back(x.second);
        }
        
        return ans;
        
    }
};