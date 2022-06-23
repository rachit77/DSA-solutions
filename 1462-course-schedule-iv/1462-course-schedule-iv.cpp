class Solution {
public:
    
    void dfs(int st, int en, vector<int> &vis, vector<vector<int>> &adj)
    {
        if(st==en) return;
        
        for(auto x:adj[st])
        {
            if(vis[x]==0)
            {
                vis[x]=1;
                dfs(x,en,vis,adj);
            }
        }
        return;
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        
        vector<vector<int>> adj(numCourses);
//         vector<int> in(numCourses,0);  //cal in degree of all node
        
//         for(int i=0;i<pre.size();i++)
//         {
//             adj[pre[i][0]].push_back(pre[i][1]);
//             in[pre[i][1]]++;
//         }
        
//         vector<int> st;
//         for(int i=0;i<in.size();i++)
//         {
//             if(in[i]==0)
//                 st.push_back(i);
//         }
        
//         vector<bool> ans(queries.size(),false);
//         for(int i=0;i<queries.size();i++)
//         {
//             int u=queries[i][0];
//             int v=queries[i][1];
            
//             for(int x:st) // x is strating pt to raech v
//             {
//                 vector<int> vis(numCourses,0);
//                 vis[x]=1;
//                 dfs(x,v,vis,adj);
                
//                 if(vis[u]==1 && vis[v]==1)
//                 {
//                     ans[i]=true;
//                     break;
//                 }
//             }
            
//             //cout<<i<<" "<<ans[i]<<endl;
//         }
//         return ans;
        
        
         for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0];
            int v=queries[i][1];
            
            // if v to u than yes
            vector<int> vis(numCourses,0);
            vis[v]=1;
            dfs(v,u,vis,adj);
                
            if(vis[u]==1)
                ans[i]=true;
        }
        return ans;
    }
};