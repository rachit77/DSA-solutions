class Solution {
public:
    //method-1 correct but TLE
//     void find(string word, int i, int j,int idx, vector<vector<char>>& board, vector<int> &vis, int &t)
//     {
//         if(idx==word.length()){
//             vis[t]=1;
//             return ;
//         } 
        
//         int r=board.size();
//         int c= board[0].size();
        
//         if(i<0 || j<0 || i>=r || j>= c || board[i][j]!=word[idx] || board[i][j]=='.')   return;
        
//         char temp=board[i][j];
//         board[i][j]='.';
        
//        find(word,i+1,j,idx+1,board,vis,t);
//        find(word,i,j+1,idx+1,board,vis,t);
//        find(word,i-1,j,idx+1,board,vis,t);
//        find(word,i,j-1,idx+1,board,vis,t);
        
//         board[i][j]=temp;
        
//         return;
//     }
    
    
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
//         int r=board.size();
//         int c= board[0].size();
        
//         vector<string> ans;
        
//         vector<int> vis(words.size(),0);
        
//         for(int t=0;t<words.size();t++)
//         {
//             for(int i=0;i<r;i++)
//             {
//                 for(int j=0;j<c;j++)
//                 {
//                     if(words[t][0]==board[i][j] && vis[t]==0)
//                     {
//                        find(words[t],i,j,0,board,vis,t);
//                     }
//                 }
//             }
//         }
        
//         for(int i=0;i<vis.size();i++)
//         {
//             if(vis[i]==1)
//                 ans.push_back(words[i]);
//         }
//         return ans;
        
//     }
    
    
    // method-2 TRIE with DFS
    struct Trie{
        struct Trie* child[26];
        bool isEnd=false;     
    };
    
    void insert(string s, Trie* root)
    {
        Trie* curr=root;
        for(int i=0;i<s.length();++i)
        {
            int ind=s[i]-'a';
            
            if(curr->child[ind]==NULL)
            {
                Trie* k=new Trie;
                for(int i=0;i<26;++i)
                   k->child[i]=NULL;

                 curr->child[s[i]-'a']= k;
            }     
            
           curr=curr->child[ind];
        }
        curr->isEnd= true;
    }
    
    void search(int i,int j, string s, Trie* root, vector<vector<char>>& board, vector<string> &ans)
    {
        if(root->isEnd==true)
        {
            // found a word
            ans.push_back(s);
            root->isEnd=false;
        }
        
         //cout<<root->isEnd<<" "<<s<<" ";
        //cout<<"ddvw"<<endl;
        int r=board.size(), c=board[0].size();
        if(i<0 || j<0 || i>=r || j>=c || board[i][j]=='.') return;
        
        char ch= board[i][j];
        
        if(root->child[ch-'a'] ==NULL) return;
        
        
        //character matches
        board[i][j]='.';
        s.push_back(ch);
        //cout<<ch<<endl;
        
        //cout<<"ggg"<<root->isEnd<<" "<<s<<endl;
        
        // if(root->isEnd==true)
        // {
        //     // found a word
        //     ans.push_back(s);
        //     root->isEnd=false;
        // }
        
        root=root->child[ch-'a'];
        search(i+1,j,s,root,board,ans);
        search(i,j+1,s,root,board,ans);
        search(i-1,j,s,root,board,ans);
        search(i,j-1,s,root,board,ans);
        s.pop_back();
        board[i][j]=ch;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       Trie* root=new Trie; 
        for(int i=0;i<26;++i)
        {
            root->child[i]=NULL;
        }
        
        
        int r=board.size(), c=board[0].size();
        
        for(auto x: words) insert(x, root);
        
        vector<string> ans;
        string s="";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
               search(i,j,s,root,board,ans); 
            }
        }
        return ans;
    }
};