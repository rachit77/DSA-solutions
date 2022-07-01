class Solution {
public:
    int find(int cur_id, int prev_color, vector<vector<int>>& costs,vector<vector<int>> &dp)
    {
       if(cur_id>=costs.size()) return 0;
         
       if(prev_color>=0 && dp[cur_id][prev_color]!=-1) return dp[cur_id][prev_color];
       
        int temp=INT_MAX;
        for(int i=0;i<costs[0].size();i++)
        {
            if(i!=prev_color) 
            {
                temp= min(temp,costs[cur_id][i] + find(cur_id+1,i,costs,dp));
            }
        }
        
       if(prev_color==-1) return temp;
        return dp[cur_id][prev_color]=temp;
    }
    
    int minCost(vector<vector<int>>& costs) {
        
        vector<vector<int>> dp(costs.size(), vector<int> (3,-1));
        return find(0,-1,costs,dp);
    }
};