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
        
        // using dfs
        int n=graph.size();
        vector<int> col(n,-1);
        
        for(int i=0;i<n;i++) {
            if(col[i]==-1)
            {
                col[i]=1;
                if(!dfs(i,col,graph))
                    return false;
            }
        }
        return true;
        
    }
};