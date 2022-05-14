class Solution {
public:
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //By using BFS Transversal
        
        vector<vector<pair<int,int>>> graph(n+1);
        
        vector<int> vis(n+1,0);
        vector<int> dis(n+1,INT_MAX);
        
        for(int i=0;i<times.size();i++)
        {
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
    
        dis[k]=0;
       
        queue<int> q;
        q.push(k);
        
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            
            for(auto x:graph[temp])
            {
                if(dis[x.first] > dis[temp]+ x.second)
                {
                    dis[x.first] = dis[temp]+ x.second;
                    q.push(x.first);
                }
            }
        }
        

        
        int temp1=0;
        for(int i=1;i<=n;i++)
        {
           temp1=max(temp1,dis[i]);
        }
        
        return (temp1==INT_MAX)?-1:temp1;
    }
};