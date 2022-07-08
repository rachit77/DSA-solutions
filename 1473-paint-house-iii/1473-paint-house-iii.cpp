// class Solution {
// public:
//     const int MAX_COST = 1000001;
    
// //     int find(int cur_id, int par_col, int neigh_count,int target,vector<int>& houses, vector<vector<int>>& cost, vector<vector<vector<int>>> &dp)
// //     {
// //         if(cur_id==houses.size() )
// //         {
// //           if(neigh_count==target)
// //             return 0;
// //           else
// //               return MAX_COST;
// //         }
        
// //         if(neigh_count > target ) return MAX_COST;
        
        
// //         if(dp[cur_id][neigh_count][par_col]!=-1)
// //             return dp[cur_id][neigh_count][par_col];
        
// //         // color the cur_id(house) with all the possible colors only if it is not colored already
// //         int min_cost=MAX_COST;
        
// //         if(houses[cur_id])  //already colored
// //         {
// //            //if(par_col!=houses[cur_id]) neigh_count++;
// //             int neigh_count = neigh_count + (houses[cur_id] != par_col);
// //            min_cost=find(cur_id+1, houses[cur_id], neigh_count,target,houses,cost,dp); 
// //         }
        
// //         else // not already colored
// //         {
// //              int totalColors = cost[0].size();
// //             for(int color=1;color<=totalColors;color++)
// //             {
// //                 //if(color!=par_col) neigh_count++;
// //                 int neigh_count = neigh_count + (color != par_col);
// //                 int cur_cost= cost[cur_id][color-1]+ find(cur_id+1,color,neigh_count,target,houses,cost,dp);
                
// //                 min_cost=min(min_cost,cur_cost);
// //             }
// //         }
        
// //         return dp[cur_id][neigh_count][par_col]=min_cost;
// //     }
        
        
// //     int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
// //         int ans;
// //         // create a 3-d dp  house idx,neigh count,color of parent
// //         vector<vector<vector<int>>> dp(101, vector<vector<int>>(101,vector<int>(21,-1)));
// //         ans=find(0,0,0,target,houses,cost,dp);
       
// //         return ans==MAX_COST ?-1:ans;
// //     }
    

    
//      int find(vector<int>& houses, vector<vector<int>>& cost, int target, int cur_id,
//                     int neigh_count, int par_col,vector<vector<vector<int>>> dp) {
       
//         if (cur_id == houses.size()) {
//             return neigh_count == target ? 0 : MAX_COST;
//         }
        
//         if (neigh_count > target) {
//             // If the neighborhoods are more than the threshold, we can't have target neighborhoods
//             return MAX_COST;
//         }
        
//         // We have already calculated the answer so no need to go into recursion
//         if (dp[cur_id][neigh_count][par_col] != -1) {
//             return dp[cur_id][neigh_count][par_col];
//         }
        
//         int min_cost = MAX_COST;
//         // If the house is already painted, update the values accordingly
//         if (houses[cur_id]) {
//             int neigh_count = neigh_count + (houses[cur_id] != par_col);
//             min_cost = 
//                 find(houses, cost, target, cur_id + 1, neigh_count, houses[cur_id],dp);
//         } else {
//             int totalColors = cost[0].size();
            
//             // If the house is not painted, try every possible color and store the minimum cost
//             for (int color = 1; color <= totalColors; color++) {
//                 int neigh_count = neigh_count + (color != par_col);
//                 int currCost = cost[cur_id][color - 1]
//                     + find(houses, cost, target, cur_id + 1, neigh_count, color,dp);
//                 min_cost = min(min_cost, currCost);
//             }
//         }
        
//         // Return the minimum cost and also storing it for future reference (memoization)
//         return dp[cur_id][neigh_count][par_col] = min_cost;
//     }
    
//     int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

//          vector<vector<vector<int>>> dp(101, vector<vector<int>>(101,vector<int>(21,-1)));
//        int ans=find(houses,cost,target,0,0,0,dp);
       
//         return ans==MAX_COST ?-1:ans;
//     }

// };
class Solution {
public:
    // Assign the size as per maximum value for different params
    int memo[100][100][21];
    // Maximum cost possible plus 1
    const int MAX_COST = 1000001;
    
    int findMinCost(vector<int>& houses, vector<vector<int>>& cost, int targetCount, int currIndex,
                    int neighborhoodCount, int prevHouseColor) {
        if (currIndex == houses.size()) {
            // If all houses are traversed, check if the neighbor count is as expected or not
            return neighborhoodCount == targetCount ? 0 : MAX_COST;
        }
        
        if (neighborhoodCount > targetCount) {
            // If the neighborhoods are more than the threshold, we can't have target neighborhoods
            return MAX_COST;
        }
        
        // We have already calculated the answer so no need to go into recursion
        if (memo[currIndex][neighborhoodCount][prevHouseColor] != -1) {
            return memo[currIndex][neighborhoodCount][prevHouseColor];
        }
        
        int minCost = MAX_COST;
        // If the house is already painted, update the values accordingly
        if (houses[currIndex]) {
            int newNeighborhoodCount = neighborhoodCount + (houses[currIndex] != prevHouseColor);
            minCost = 
                findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, houses[currIndex]);
        } else {
            int totalColors = cost[0].size();
            
            // If the house is not painted, try every possible color and store the minimum cost
            for (int color = 1; color <= totalColors; color++) {
                int newNeighborhoodCount = neighborhoodCount + (color != prevHouseColor);
                int currCost = cost[currIndex][color - 1]
                    + findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, color);
                minCost = min(minCost, currCost);
            }
        }
        
        // Return the minimum cost and also storing it for future reference (memoization)
        return memo[currIndex][neighborhoodCount][prevHouseColor] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // Marking all values to -1 to denote that we don't have the answer ready for these params yet
        memset(memo, -1, sizeof(memo));
        int answer = findMinCost(houses, cost, target, 0, 0, 0);
        
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return answer == MAX_COST ? -1 : answer;
    }
};