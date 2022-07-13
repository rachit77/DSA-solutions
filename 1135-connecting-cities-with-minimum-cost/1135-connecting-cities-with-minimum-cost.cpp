class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
       
        // minimum spanning tree
        
        //make a adj list
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it:connections)
        {
            int u=it[0]-1;
            int v=it[1]-1;
            int weight=it[2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        
        vector<bool> is_included(n,false);
        vector<int> wt(n,INT_MAX);
        
        //make a min heap edge_wt, edge
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // st from 1st node
        wt[0]=0;
        
        pq.push({0,0});
       
        for(int i=0;i<n-1;i++)  //need to add n-1 edge in total
        {
            //find the min edge weight from wt which is not yet included in mst
            int min_wt=INT_MAX,min_edge;
            // for(int j=0;j<n;j++)
            // {
            //     if(is_included[j]==false && wt[j]<min_wt)
            //     {
            //         min_edge=j;
            //         min_wt=wt[j];
            //     }
            // }
            
            while(!pq.empty() && is_included[pq.top().second]!=false)
            {
                pq.pop();
            }
            
            min_edge=pq.top().second;
            min_wt=pq.top().first;
            pq.pop();
            
            is_included[min_edge]=true;
            
            //itearte over adj of min_edge to edit their weight
            for(auto it:adj[min_edge])
            {
                int v=it.first;
                int weight=it.second;
                
                if(is_included[v]==false && weight < wt[v])
                {
                    wt[v]=weight;
                    pq.push({weight,v});
                }
            }   
        }
        
        int sum=0;
        
        for(auto it:wt) 
        {
            if(it==INT_MAX)
            {
                sum=-1;
                break;
            }
            sum+=it;
        }
        
        return sum; 
    }
};