class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<string> ans;
        
        vector<int> count(26,0);
        
        for(auto it:words[0])
            count[it-'a']++;
        
        for(int i=1;i<words.size();i++)
        {
            vector<int> temp(26,0);
            for(int j=0;j<words[i].length();j++)
            {
               temp[words[i][j]-'a']++;
            }
            
            for(int z=0;z<26;z++)
            {
                count[z]=min(count[z],temp[z]);
            }
        }
        
        for(int i=0;i<26;i++)
        {
            while(count[i]--)
            {
                string s;
                s.push_back(i+'a');
                ans.push_back(s);
            }
        }
        
        return ans;
 
       
    }
};