class Solution {
public:
    int find(string &s, string &word)
    {
        int cnt=0;
        int word_idx=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==word[word_idx])
                word_idx++;
            
             if(word_idx==word.length())
                return 1;
            
        }
        
       
        
        return 0;
    }
    
	// bool find(string &a, string &b)
	// {
	// 	int n = a.size(), m = b.size();
	// 	int i = 0, j = 0;
	// 	while (i < n && j < m) {
	// 		if (a[i] == b[j]) {
	// 			i++, j++;
	// 		}
	// 		else i++;
	// 	}
	// 	return j == m;
	// }
    
    
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
    
//     int numMatchingSubseq(string s, vector<string>& words) {
        
//         vector<vector< pair<string,int>> > mp(26);
        
//         for(auto word:words)
//         {
//             mp[word[0]-'a'].push_back({word,0});
//         }
        
//         int ans=0;
        
//         for(int i=0;i<s.length();i++)
//         {
//             if( mp[s[i]-'a'].size()!=0) {
            
//             for(auto x:mp[s[i]-'a'])
//             {
//                 string word=x.first;
//                 int idx=x.second;
                
//                 if(word.length()-1==idx) ans++;
//                 else
//                 {
                   
//                      //cout<<word<<" "<<idx<<endl;
//                      mp[word[idx+1]-'a'].push_back({word,idx+1});
                    
//                 }
//             }
           
//             mp[s[i]-'a'].clear();
//             }
//         }
        
//         return ans;
//     }
};