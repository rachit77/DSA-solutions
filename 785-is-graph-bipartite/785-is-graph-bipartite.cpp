class Solution {
public:
    bool dfs(int i, vector<int> &col, vector<vector<int>>& graph)
    {
        for(auto x:graph[i])
        {
            if(col[x]==-1)
            {
                col[x]=1-col[i];
                if(!dfs(x,col,graph))
                    return false;
            }
            else if(col[x]==col[i])
                return false;
        }
        
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
//         // using dfs
         int n=graph.size();
//         vector<int> col(n,-1);
        
//         for(int i=0;i<n;i++) {
//             if(col[i]==-1)
//             {
//                 col[i]=1;
//                 if(!dfs(i,col,graph))
//                     return false;
//             }
//         }
//         return true;
        
        
        
//           vector<vector<int>> adj(n+1);
        
//         for(int i=0;i<dislikes.size();i++)
//         {
//             adj[dislikes[i][0]].push_back(dislikes[i][1]);
//         }
        
        // bipartite graph using bfs
        vector<int> vis(n+1,-1);
        
        int cnt=0;
        
        // graph can be disconnected
        for(int i=0;i< n;i++)
        {
            queue<int> q;
            if(vis[i]==-1) // node not visited
            {
                vis[i]=1;
                q.push(i);
                while(!q.empty())
                {
                  int node=q.front();
                    q.pop();
                    
                    for(auto x:graph[node])
                    {
                        if(vis[x]==-1)
                        {
                            vis[x]=1-vis[node];
                            q.push(x);
                        }
                        else if(vis[node] == vis[x])
                        {
                            cout<<vis[node]<<" "<<i<<endl;
                           return false; 
                        }
                            
                    }
                }
            }
        }
        
        return true;
        
        
        
    }
};