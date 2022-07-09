class Solution {
public:
    
    //method-2 mm=emo TLE
//     int find(int st,int &k,vector<int>& nums,vector<int> &dp)
//     {
//         if(st==nums.size()-1) return nums[nums.size()-1];
        
//         if(st>=nums.size()) return INT_MIN;
        
//         if(dp[st]!=-1) return dp[st];
        
//         int max_sum=INT_MIN;
//         for(int i=st+1;i<=st+k;i++)
//         {
//             if(i>nums.size()) break;
//             int temp=find(i,k,nums,dp);
//             max_sum=max(max_sum,temp);
//         }
        
//         return dp[st]=(max_sum==INT_MIN)?max_sum:max_sum+nums[st];
//     }
    
    
    int maxResult(vector<int>& nums, int k) {
       
        int n=nums.size();
        
        //method-1  top dowm with max heap nlogn
//         vector<int> dp(n,0);
//         dp[0]=nums[0];
//         priority_queue<pair<int,int>, vector<pair<int,int>> > pq;
//         pq.push({nums[0],0});
        
//         for(int i=1;i<n;i++)
//         {
//             int temp;
//             while(!pq.empty() && pq.top().second<(i-k))
//             {
//                 pq.pop();
//             }
            
//             temp=pq.top().first;
//             dp[i]=nums[i]+temp;
            
//             pq.push({dp[i],i});
//         }
//         return dp[n-1];
        
        // //Method-2 recursion and memoization TLE
        // vector<int> dp(n,-1);
        // return find(0,k,nums,dp);
        
        
        //method-3 DP + deque
         vector<int> dp(n);
          dp[0]=nums[0];
        deque<int> dq; //stores the index
        dq.push_back(0);
        
        for(int i=1;i<n;i++)
        {
            //pop the invalid indices
            while(!dq.empty() && dq.back()<i-k) dq.pop_back();
            
            dp[i]=nums[i]+ dp[dq.back()];
            
            //pop the smaller values than dp[i]
            while(!dq.empty() && dp[i]>=dp[dq.front()])
                dq.pop_front();
            
            dq.push_front(i);
        }
        return dp[n-1];
    }
};