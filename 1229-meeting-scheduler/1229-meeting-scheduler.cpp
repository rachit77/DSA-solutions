class Solution {
public:
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int n=slots1.size();
        int m=slots2.size();
        int i=0,j=0;
        vector<int> ans;
        
       // sort both the vectors acc to starting time
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
            
        while(i<n &&j<m)
        {
            int diff= min(slots2[j][1],slots1[i][1]) - max(slots1[i][0], slots2[j][0]);
            
            if(diff>=duration) //found
            {
                ans.push_back(max(slots1[i][0], slots2[j][0]));
                ans.push_back(max(slots1[i][0], slots2[j][0])+duration);
                break;
            }
            
            if(slots2[j][1] > slots1[i][1])
                i++;
            else
                j++;
        }
        
        return ans;
    }
   
    //method-2 heaps
//  struct comp{   
//     bool operator()( pair<int,int> const& a, pair<int,int> const& b)
//     {
//         if(a.first==b.first)
//             return a.second>b.second;
        
//         return a.first> b.first;
//     }
//  };
    
//     vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration){
        
//         priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q;
        
//         for(int i=0;i<slots1.size();i++)
//         {
//             if(slots1[i][1]-slots1[i][0] >=duration)
//                 q.push({slots1[i][0],slots1[i][1]});
//         }
        
//         for(int i=0;i<slots2.size();i++)
//         {
//             if(slots2[i][1]-slots2[i][0] >=duration)
//                 q.push({slots2[i][0],slots2[i][1]});
//         }
        
//         vector<int> ans;
// //         pair<int,int> sl1;
       
// //         if(!q.empty()){
// //         sl1=q.top();
// //         q.pop();
// //         }
        
//         while(q.size()>1)
//         {
//             pair<int,int> sl1=q.top();
//             q.pop();
//             pair<int,int> sl2=q.top();
//             //q.pop();
            
//             if(sl1.second>= sl2.first+ duration) //found duration
//             {
//                 ans.push_back(sl2.first);
//                 ans.push_back(sl2.first+ duration);
//                 break;
//             }
            
//             // if(sl2.second> sl1.second)
//             //     sl1=sl2;
//         }
//         return ans;
//     }
};