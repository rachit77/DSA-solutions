class Solution {
public:
//     int find(string &s, string &word)
//     {
//         int cnt=0;
//         int word_idx=0;
//         for(int i=0;i<s.length();i++)
//         {
//             if(s[i]==word[word_idx])
//                 word_idx++;
            
//         }
        
//         if(word_idx==word.length())
//             return 1;
        
//         return 0;
//     }
    
    bool find(string &a, string &b)
	{
		int n = a.size(), m = b.size();
		int i = 0, j = 0;
		while (i < n && j < m) {
			if (a[i] == b[j]) {
				i++, j++;
			}
			else i++;
		}
		return j == m;
	}
    
    
    int numMatchingSubseq(string s, vector<string>& words) {
        //method-1
        int ans=0;
        
        unordered_map<string,int> mp;
        
        for(auto &word:words)
        {
            mp[word]++;
        }
        for(auto &word:mp)
        {
            string x=word.first;
            if( find(s,x) )
            ans+=word.second;
        }
        return ans;
    }
};