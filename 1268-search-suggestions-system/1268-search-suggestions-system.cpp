class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd=false;
        
        TrieNode()
        {
            for(int i=0;i<26;i++)
            {
                child[i]=NULL;
            }
        }
    };
    struct TrieNode* root;
    
    void insert(TrieNode* node, string s)
    {
        TrieNode* cur=node;
        
        for(int i=0;i<s.length();i++)
        {
            if(cur->child[s[i]-'a'] ==NULL)
            {
                cur->child[s[i]-'a'] = new TrieNode();
            }
            cur= cur->child[s[i]-'a'];
        }
        cur->isEnd=true;
    }
    
    TrieNode* search(TrieNode* node, string s)
    {
        TrieNode* cur=node;
        for(int i=0;i<s.length();i++)
        {
            if(cur->child[s[i]-'a']==NULL)
            {
                return NULL;
            }
            else
            {
                cur=cur->child[s[i]-'a'];
            }
        }
        
        return cur;
    }
    
    void findSuggestion(string &st,TrieNode* node, vector<string> &temp)
    {
        TrieNode* cur=node;
        
        if(cur->isEnd==true && temp.size() <3)
        {
            temp.push_back(st);
        }
        
        for(int i=0;i<26;i++)
        {
            if(cur->child[i]!=NULL)
            {
                st.push_back((char)('a'+i));
                findSuggestion(st,cur->child[i],temp);
                st.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        root= new TrieNode();
        
        for(int i=0;i<products.size();i++)
        {
            insert(root,products[i]);
        }
        
        
        for(int i=1;i<=searchWord.length();i++)
        {
            vector<string> temp;
            string s=searchWord.substr(0,i);
           // cout<<s<<endl;
            TrieNode* node= search(root,s);
            
           // if(node->isEnd==true) temp.push_back(s);
            
            if(node!=NULL)
            {
                findSuggestion(s,node,temp);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};