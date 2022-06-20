class Solution {
public:
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
    
    void insert(TrieNode *node, string s)
    {
        TrieNode* cur=node;
        int flag=0;
        
        for(int i=0;i<s.length();i++)
        {
            
            if(cur->child[s[i]-'a'] ==NULL)
            {
                flag=1;
                cur->child[s[i]-'a']= new TrieNode;
            }
            
            cur=cur->child[s[i]-'a'];
        }
        
        if(flag) cur->isEnd= true;
    }
    
    void count(TrieNode* node, int &ans, int d)
    {
        // if(node->isEnd==true)
        // {
        //     d++;
        //     ans+=d;
        //     return;
        // }
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
        
    int minimumLengthEncoding(vector<string>& words) {
        
        root=new TrieNode;
        
        for(int i=0;i<words.size();i++)
        {
            reverse(words[i].begin(), words[i].end());
            insert(root, words[i]);
        }
        
        int ans=0;
        
        count(root,ans,0);
        return ans;
        
    }
};