class Solution {
public:
//     vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
      
//         int n=slots1.size();
//         int m=slots2.size();
//         int i=0,j=0;
//         vector<int> ans;
        
//         while(i<n && j<m)
//         {
//             int a_st=slots1[i][0];
//             int a_end=slots1[i][1];
            
//             int b_st=slots2[j][0];
//             int b_end =slots2[j][1];
            
//             if()
//         }
        
//     }
    
    //method-2 heaps
 struct comp{   
    bool operator()( pair<int,int> const& a, pair<int,int> const& b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        
        return a.first> b.first;
    }
 };
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration){
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q;
        
        for(int i=0;i<slots1.size();i++)
        {
            if(slots1[i][1]-slots1[i][0] >=duration)
                q.push({slots1[i][0],slots1[i][1]});
        }
        
        for(int i=0;i<slots2.size();i++)
        {
            if(slots2[i][1]-slots2[i][0] >=duration)
                q.push({slots2[i][0],slots2[i][1]});
        }
        
        vector<int> ans;
        
        // while(!q.empty())
        // {
        //     pair<int,int> sl1=q.top();
        //     q.pop();
        //     cout<<sl1.first<<" "<<sl1.second<<endl;
        // }
        
        while(q.size()>1)
        {
            cout<<"yg";
            pair<int,int> sl1=q.top();
            q.pop();
            cout<<sl1.first<<" "<<sl1.second<<endl;
            pair<int,int> sl2=q.top();
            cout<<sl2.first<<" "<<sl2.second<<endl;
            
            if(sl1.second>= sl2.first+ duration) //found duration
            {
                ans.push_back(sl2.first);
                ans.push_back(sl2.first+ duration);
                break;
            }
        }
        return ans;
    }
};