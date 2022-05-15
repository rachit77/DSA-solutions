class Solution {
public:
    int flag=0;
    
    
    void toposort(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st, vector<int> curVis)
    {
           vis[node]=1;
           curVis[node]=1;
        
        for(auto x: adj[node])
        {
            if(curVis[x]==1)
                flag=1;
            
            
            if(vis[x]==0)
            {
                toposort(x,vis,adj,st,curVis);
            }
            
        }
        st.push(node);
        
       // cout<<"djcn"<<node<<endl;;
        
        
        return;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //make a adjancy list
        // find topological sort
        // if all courses are in topo sort return true
        
        vector<vector<int>> adj(numCourses+1); // 0-> numCourses
        
        for(int i=0;i< prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> vis(numCourses,0);
        vector<int> curVis(numCourses,0);
        stack<int> st;
        
        // find topo sort using dfs
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                toposort(i,vis,adj,st,curVis);
            }
        }
        
        int count=0;
        while(!st.empty())
        {
            count++;
            st.pop();
        }
        cout<<count<<endl;
        
        return (count!=numCourses || flag==1)?0:1;
        
    }
};