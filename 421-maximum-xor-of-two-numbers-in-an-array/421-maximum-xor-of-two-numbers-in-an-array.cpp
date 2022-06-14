class Solution {
public:
    struct TrieNode {
        struct TrieNode* child[2];
        
        TrieNode(){
            child[0]=NULL;
            child[1]=NULL;
        }
    };
    
    TrieNode* node;
    
    void insert(int num)
    {
        TrieNode* temp=node;
        for(int i=31;i>=0;i--)
        {
            bool set= num& (1<<i);
            if(temp->child[set]==NULL)
            {
                temp->child[set]=new TrieNode();
            }
            temp=temp->child[set];
        }
    }
    
    int findMax(int num)
    {
        TrieNode* temp=node;
        int k=0;
        for(int i=31;i>=0;i--)
        {
            bool set= num&(1<<i);
            
            if(temp->child[!set]!=NULL) //opposite bits
            {
                temp=temp->child[!set];
                 k=k+ (1<<i);
            }
            else // bits same  so xor value =0
                temp=temp->child[set];
        }
         return k;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        //naive approach tc:O(n^2)
       // int ans=0,i,j,n=nums.size();
        
        // for(i=0;i<n-1;i++)
        // {
        //     for(j=i+1;j<n;j++)
        //     {
        //        int temp=nums[i] ^ nums[j];
        //         ans=max(ans,temp);
        //     }
        // }
            
        //return ans;
       
        
        //method-2 trie
        
        node=new TrieNode();
        int i,n=nums.size();
        if(n<=1) return 0;
        int ans=INT_MIN;
        insert(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            int temp=findMax(nums[i]);
            ans=max(ans,temp);
            insert(nums[i]);
        }
        
        return ans;
    }
};