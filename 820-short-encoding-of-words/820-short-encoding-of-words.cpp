class Solution {
private:
    struct TrieNode {
        struct TrieNode* child [26];
        bool isEnd=false;
        
        TrieNode()
        {
            for(int i=0;i<26;i++)
                child[i]=NULL;
        }
    };
    
    TrieNode* root;
    
     static bool comp(const string &a, const string &b)
    {
        return a.size() > b.size();
    }
         
    int insert(TrieNode *node, string s)
    {
        TrieNode* cur=node;
        bool newBranch=false;
        
        for(int i=0;i<s.length();i++)
        {
            
            if(cur->child[s[i]-'a'] ==NULL)
            {
                newBranch=true;
                cur->child[s[i]-'a']= new TrieNode;
            }
            
            cur=cur->child[s[i]-'a'];
        }
        
        cur->isEnd= true;
        
        //if(newBranch) cur->isEnd= true;
        
        return newBranch ? s.size()+1:0;
    }
    
    void count(TrieNode* node, int &ans, int d)
    {
        int flag=1;
        for(int i=0;i<26;i++)
        {
            if(node->child[i]!=NULL)
            {
                flag=0;
                count(node->child[i],ans, d+1);
            }
        }
        
        if(flag==1 && node->isEnd==true)
        {
            d++;
            ans+=d;
        }
                     
        return;
    }
      
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        root=new TrieNode;
        int ans=0;
        sort(words.begin(), words.end(),comp);
        for(int i=0;i<words.size();i++)
        {
            reverse(words[i].begin(), words[i].end());
            ans+=insert(root, words[i]);
        }
        
        
        
        //count(root,ans,0);
        return ans;
        
    }
    
    //method-2
// private:
//     static bool comp(const string &a, const string &b)
//     {
//         return a.size() > b.size();
//     }
// public:
//     int minimumLengthEncoding(vector<string>& words) {
        
//         sort(words.begin(), words.end(), comp);
        
//         int ans=0;
//         string word=words[0]+"#";
        
//         for(int i=1;i<words.size();i++)
//         {
//             string str= words[i]+"#";
            
//             if(word.find(str)== string::npos) // not found
//             {
//                 word+=str;
//             }
//         }
        
//         return word.length();
//     }
};