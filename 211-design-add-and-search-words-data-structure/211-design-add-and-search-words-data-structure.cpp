// class TrieNode{
//     public:
//         TrieNode *child[26];
//         bool isEnd=false;
    
//     TrieNode(){
//         for(int i=0;i<26;i++)
//         {
//             child[i]=NULL;
//         }
//     }
// };

class WordDictionary {
    
private:
     struct TrieNode{
        TrieNode *child[26];
        bool isEnd=false;
    TrieNode(){
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
    };
    
    bool search_helper(int st, string &word, TrieNode* cur)
    {
        for(int i=st;i<word.length();i++)
        {
            char ch=word[i];
            if(ch=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(cur->child[j] && search_helper(i+1,word,cur->child[j])) return true;
                }
                
                return false;
            }
            else //not a '.'
            {
                if(cur->child[ch-'a']==NULL) return false;
                cur=cur->child[ch-'a'];
            }
        }
        return cur->isEnd;
    }

public:
      
     TrieNode* node;
    
    WordDictionary() {
       node=new TrieNode; 
    }
    
    void addWord(string word) {
      TrieNode* cur=node;
          
        for (char c : word)
        {
            if (!cur->child[c - 'a'])
                cur->child[c - 'a'] = new TrieNode();
            cur = cur->child[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return search_helper(0,word,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */