class Solution {
public:
//     void mark(vector<int> &v, vector<int>& vis)
//     {
//             for(int i=v[0];i<=v[1];i++)
//             {
//                 vis[i]=1;
//             }
//         return;
//     }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
      // using stack
        stack<pair<int,int>> st;
        
       sort(intervals.begin(), intervals.end());
        for(int i=0;i<intervals.size();i++)
        {
           
            if(st.empty())
            {
                st.push({intervals[i][0],intervals[i][1]});
                 //cout<<intervals[i][0]<<" "<<i<<endl;
            }
            else
            {
if(intervals[i][0] <=st.top().second && intervals[i][1] >=st.top().second )
                {
                    //update end2
                    st.top().second=intervals[i][1];
    
                }
                else if(intervals[i][0] >st.top().second)
                {
                    st.push({intervals[i][0],intervals[i][1]});
                }
                    
            }
        }
        
        
        vector<vector<int>> ans;
        while(!st.empty())
        {
            pair<int,int> p=st.top();
            st.pop();
            
            vector<int> temp;
            temp.push_back(p.first);
            temp.push_back(p.second);
            
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};