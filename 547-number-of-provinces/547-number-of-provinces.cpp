class Solution {
public:
    void find(int node,vector<vector<int>>& isConnected, vector<bool> &vis)
    {
             vis[node]=true;
        
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[node][i]==1 && vis[i]==false)
            {
                find(i,isConnected,vis);
            }
        }
        return ;
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                ans++;
                find(i,isConnected,vis);
            }
        }
        return ans;
    }
};