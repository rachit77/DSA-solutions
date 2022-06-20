class Solution {
// private:
//     struct TrieNode {
//         struct TrieNode* child [26];
//         bool isEnd=false;
        
//         TrieNode()
//         {
//             for(int i=0;i<26;i++)
//                 child[i]=NULL;
//         }
//     };
    
//     TrieNode* root;
    
//     void insert(TrieNode *node, string s)
//     {
//         TrieNode* cur=node;
//         int flag=0;
        
//         for(int i=0;i<s.length();i++)
//         {
            
//             if(cur->child[s[i]-'a'] ==NULL)
//             {
//                 flag=1;
//                 cur->child[s[i]-'a']= new TrieNode;
//             }
            
//             cur=cur->child[s[i]-'a'];
//         }
        
//         if(flag) cur->isEnd= true;
//     }
    
//     void count(TrieNode* node, int &ans, int d)
//     {
//         int flag=1;
//         for(int i=0;i<26;i++)
//         {
//             if(node->child[i]!=NULL)
//             {
//                 flag=0;
//                 count(node->child[i],ans, d+1);
//             }
//         }
        
//         if(flag==1 && node->isEnd==true)
//         {
//             d++;
//             ans+=d;
//         }
                     
//         return;
//     }
      
// public:
//     int minimumLengthEncoding(vector<string>& words) {
        
//         root=new TrieNode;
        
//         for(int i=0;i<words.size();i++)
//         {
//             reverse(words[i].begin(), words[i].end());
//             insert(root, words[i]);
//         }
        
//         int ans=0;
        
//         count(root,ans,0);
//         return ans;
        
//     }
    
    //method-2
private:
    static bool comp(const string &a, const string &b)
    {
        return a.size() > b.size();
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        sort(words.begin(), words.end(), comp);
        
        int ans=0;
        string word=words[0]+"#";
        
        for(int i=1;i<words.size();i++)
        {
            string str= words[i]+"#";
            
            if(word.find(str)== string::npos) // not found
            {
                word+=str;
            }
        }
        
        return word.length();
    }
};