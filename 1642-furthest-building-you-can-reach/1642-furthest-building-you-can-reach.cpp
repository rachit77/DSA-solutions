class Solution {
public:
    
    //method-1 recursion memoization TLE
//     int dp[100001][1000000002][100001];
//     int find(int pos,vector<int>& heights, int bricks, int ladders)
//     {
//         if((bricks<0 || ladders<0)) return 0;
        
//         if(dp[pos][bricks][ladders]!=-1) return dp[pos][bricks][ladders];
//         if(pos==heights.size()-1) return 1;
        
//         int h= heights[pos+1]-heights[pos];
//         int a=0,b=0;
//         if(h<=0) // no need of ladder or bricks
//         {
//           a=find(pos+1,heights, bricks, ladders);  
//         }
//         else
//         {
//             a=find(pos+1,heights, bricks-h, ladders);  
//             b=find(pos+1,heights, bricks, ladders-1);  
//         }
        
//         return dp[pos][bricks][ladders]=1+ max(a,b);
        
//     }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders)    { 
//         memset(dp,-1,sizeof(dp));
//         int ans=find(0,heights,bricks,ladders);
//         return ans-1;    
//     }
    
    //method-2  max heap
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
//         priority_queue<int> q;
//         int i;
//         for(i=0;i<heights.size()-1;i++)
//         {
//             int diff=heights[i+1]-heights[i];
            
//             if(diff<=0)
//                 continue;
            
//             q.push(diff);
//             bricks-=diff;
            
//             if(bricks<0)
//             {
//                 bricks+= q.top();
//                 q.pop();
//                 ladders--;
//             }
            
//             if(ladders<0) break;
//         }
        
//         return i;
//     }
    
    
    //method-3 Binary search
    bool find(int mid,vector<int>& heights, int bricks, int ladders)
    {
        vector<int> v;
        for(int i=0;i<mid;i++)
        {
            int dif= heights[i+1] - heights[i];
            if(dif>0)
                v.push_back(dif);
        }
        
        sort(v.begin(),v.end(), greater<int>());
        
        for(int i=ladders;i<v.size();i++)
        {
          bricks-=v[i];
          if(bricks<0) return false;
        }
        return true;
    }
     int furthestBuilding(vector<int>& heights, int bricks, int ladders)      {
         int lo=0,h=heights.size()-1;
         
         while(lo<h)
         {
             int mid = lo + (h - lo + 1) / 2;
             bool isReachable= find(mid,heights,bricks,ladders);
             
             if(isReachable==true)
                 lo=mid;
             else
                 h=mid-1;
         }
         
         return lo;
   }
    
    
};