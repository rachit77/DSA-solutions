class Solution {
public:
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<vector<int>> &adj, vector<vector<int>> &ans, int &time)
    {
        vis[node]=1;
        tin[node]=low[node]=time++;
        
        for(auto x:adj[node])
        {
            if(x== parent)
                continue;
            
            if(!vis[x]) //not visited
            {
                dfs(x,node,tin,low,vis,adj,ans,time);
                
                low[node]=min(low[node], low[x]);
                
                if(low[x]> tin[node])
                {
                    ans.push_back({node,x});
                }
            }
            else
            {
                low[node]=min(low[node], tin[x]);
            }
        }
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        //make a adj list
        vector<vector<int>> adj(n);
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        //tin - time of insertion at the node
        //low - lowest time of insertion at the node
        //vis - mark visited node 
        
        vector<int> tin(n,-1),low(n,-1),vis(n,0);
        
        vector<vector<int>> ans;
        int time=0; 
        
        dfs(0,-1,tin,low,vis,adj,ans,time);
        return ans;
        
    }
};