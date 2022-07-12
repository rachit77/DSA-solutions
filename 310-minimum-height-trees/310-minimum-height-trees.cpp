class Solution {
public:
    //method-1 TLE
//     int find_height(int root, vector<vector<int>> &adj, vector<int> &vis)
//     {
//         int h=0;
//         vis[root]=1;
        
//         for(int i=0;i<adj[root].size();i++)
//         {
//             if(vis[adj[root][i]]==0){
//                 int temp=1+find_height(adj[root][i],adj,vis);
//                 h = max(h,temp);
//             }
//         }
        
//         return h;
//     }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //make a adjancy list
       
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        
        vector<int> ans;
        
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1) //leaf node
            {
                q.push(i);
                indegree[i]--;
            }
        }
        
        
        while(!q.empty())
        {
            int siz=q.size();
            ans.clear();
            while(siz--)
            {
                int node=q.front();
                ans.push_back(node);
                q.pop();
                
                for(auto it: adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==1) q.push(it);
                }
            }
        }
        
        if(n==1) ans.push_back(0);
        return ans;
        
        //method-1
//         vector<int> h(n,0);      
//         for(int i=0;i<n;i++)
//         {
//             vector<int> vis(n,0);
//             h[i]=find_height(i,adj,vis);
//         }
    
//         int min_num=INT_MAX;
//         for(auto it: h) min_num=min(min_num,it);
        
//         for(int it=0;it<n;it++)
//         {
//             if(h[it]==min_num)
//             ans.push_back(it);
//         }
            
 //       return ans;
    }
};