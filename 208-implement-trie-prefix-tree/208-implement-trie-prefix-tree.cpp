class Trie {
    
private:
    struct TrieNode{
        TrieNode *child[26];
        bool isEnd=false;
    };
    
    struct TrieNode* node;
public:
    Trie() {
         node=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur=node;
        
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(cur->child[ch-'a']==NULL) 
                cur->child[ch-'a']=new TrieNode();
            
            cur=cur->child[ch-'a'];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        
        TrieNode* cur=node;
        for(auto x:word)
        {
            if(cur->child[x-'a']==NULL) return false;
            cur=cur->child[x-'a'];
        }
        
        return cur->isEnd;   
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=node;
        for(auto x:prefix)
        {
            if(cur->child[x-'a']==NULL) return false;
            cur=cur->child[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */