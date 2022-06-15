class Solution {
    
struct new_queries{
    int x,m,id;
};
    
struct TrieNode {
    struct TrieNode* child[2];
    
    TrieNode(){
        child[0]=NULL;
        child[1]=NULL;
    }
};
TrieNode* root;
  
    
void insert(int num)
{
    TrieNode* cur=root;
    
    for(int i=31;i>=0;i--)
    {
        bool set= num & (1<<i);
        if(cur->child[set]==NULL)
        {
            cur->child[set]=new TrieNode;
        }
        cur=cur->child[set];
    }
    return ;
}
    
int findMaxXor(int num)
{
    
    TrieNode* cur=root;
    
    int k=0;
    for(int i=31;i>=0;i--)
    {
        bool set=num &(1<<i);
        
        if(cur->child[!set]!=NULL)
        {
            cur=cur->child[!set];
            k= k + (1<<i);
        }
        else
        {
            cur=cur->child[set];
        }
        
    }
    return k;
}
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int q_len=queries.size();
        
        vector<pair<int,pair<int,int>>> new_queries;  //m,x,id
        
        for(int i=0;i<q_len;i++)
        {
           new_queries.push_back({queries[i][1],{queries[i][0], i}}) ;
        }
        
        // sort arr
        sort(new_queries.begin(), new_queries.end());
        vector<int> ans(q_len);
        
        root=new TrieNode;
        
        int j=0;
        
        for(int i=0;i<q_len;i++) // iterating over queries
        {
            int m=new_queries[i].first;
            int x=new_queries[i].second.first;
            int id=new_queries[i].second.second;
            
            while(j<n && nums[j]<=m)
            {
                insert(nums[j]);
                j++;
            }
            
            if(j==0) ans[id]=-1;
            else
            ans[id]= findMaxXor(x);
        }
        
        return ans;
        
    }
};