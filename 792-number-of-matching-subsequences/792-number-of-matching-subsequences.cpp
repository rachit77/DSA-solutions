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
            
//              if(word_idx==word.length())
//                 return 1;
            
//         }
//         return 0;
//     }
    
    
//     int numMatchingSubseq(string s, vector<string>& words) {
//         //method-1
//         int ans=0;
        
//         unordered_map<string,int> mp;
        
//         for(auto &word:words)
//         {
//             mp[word]++;
//         }
//         for(auto &word:mp)
//         {
//             string x=word.first;
//             if( find(s,x) )
//             ans+=word.second;
//         }
//         return ans;
//     }
    
    
    //method-2 
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
    
    
    //method-3
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<int,vector<int>> mp;
        int i=0;
        for(auto ch:s) mp[ch-'a'].push_back(i++);
        
        int ans=0;
        for(i=0;i<words.size();i++)
        {
            string curr=words[i];
            int max_id=-1;
            
          int flag=0;
            for(int j=0;j<curr.size();j++) //transversing over a word
           {
              char ch=curr[j];
              flag=0;
              for(int k=0;k<mp[ch-'a'].size();k++) //transavesing over vector of indices
              {
                  if(mp[ch-'a'][k] >max_id)
                  {
                      max_id=mp[ch-'a'][k];
                      flag=1;
                      break;
                  }
              }
               
               if(flag==0) break;  
           }
            
            if(flag==1) ans++;
            
        }
        
        return ans;
    }
};