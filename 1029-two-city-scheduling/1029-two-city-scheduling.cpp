class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        vector<int> dif;
        int cost=0,i,n;
        
        n=costs.size();
        
        
        for(i=0;i<n;i++) {
            
            cost+=costs[i][0];
            
            dif.push_back(costs[i][1]-costs[i][0]);
            
        }
        
        sort(dif.begin(),dif.end());
        
        for(i=0;i<n/2;i++)
            cost+=dif[i];
        
        return cost;
        
        
    }
};