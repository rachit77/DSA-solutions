class Solution {
public:
    
    //method-1 memoization and recursion
//     int find(int cur_id, int prev_color, vector<vector<int>>& costs,vector<vector<int>> &dp)
//     {
//        if(cur_id>=costs.size()) return 0;
         
//        if(prev_color>=0 && dp[cur_id][prev_color]!=-1) return dp[cur_id][prev_color];
       
//         int temp=INT_MAX;
//         for(int i=0;i<costs[0].size();i++)
//         {
//             if(i!=prev_color) 
//             {
//                 temp= min(temp,costs[cur_id][i] + find(cur_id+1,i,costs,dp));
//             }
//         }
        
//        if(prev_color==-1) return temp;
//         return dp[cur_id][prev_color]=temp;
//     }
    
    int minCost(vector<vector<int>>& costs) {
        
        // vector<vector<int>> dp(costs.size(), vector<int> (3,-1));
        // return find(0,-1,costs,dp);
        
        //method-2 tabulation
        int tot_colors=costs[0].size();
        int houses= costs.size();
        
        vector<int> prev_dp(tot_colors,-1);
        vector<int> cur_dp(tot_colors,INT_MAX);
        
        prev_dp=costs[0];
        
        for(int i=1;i<houses;i++)
        {
            //iterate over cur_dp
            for(int j=0;j<tot_colors;j++)
            {
                cur_dp[j]=INT_MAX;
                for(int k=0;k<tot_colors;k++) // prev_dp
                {
                    if(j!=k)
                    {
                        cur_dp[j]=min(cur_dp[j],prev_dp[k]+costs[i][j]);
                    }
                }
            }
            
            prev_dp=cur_dp;
            
        }
        
        int min_cost=INT_MAX;
        for(int cost:prev_dp)
            min_cost=min(min_cost,cost);
        
        return min_cost;
    }
};