class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       
        int n=cost.size();
        // vector<int> dp(n);
        
        int f=cost[0];
        int s=cost[1];
        
        for(int i=2;i<n;i++)
        {
            int temp=cost[i]+ min(f,s);
            f=s;
            s=temp;
        }
        // ans is min of last two
        return min(f,s);
    }
};