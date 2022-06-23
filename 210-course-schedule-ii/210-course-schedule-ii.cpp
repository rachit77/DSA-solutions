class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> ans;
        vector<int> in(numCourses,0);
        
        vector<vector<int>> adj(numCourses);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        vector<int> vis(numCourses,0);
        
        for(int i=0;i<in.size();i++)
        {
            if(in[i]==0)
            {
                q.push(i);
                vis[i]=1;
            }   
        }
         
        while(!q.empty())
        {
            int num=q.front();
            ans.push_back(num);
            q.pop();
            
            
            for(auto x:adj[num])
            {
                in[x]--;
                if(in[x]==0 &&vis[x]==0)
                {
                     q.push(x);
                    vis[x]=1;
                }
                   
            }
        }
        
        if(ans.size()==numCourses)
            return ans;
        
        vector<int> res;
        return res;
        
    }
};