class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]==b[0]) return a[1]>b[1];
        
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), comp);
        
        int n=envelopes.size();
//         vector<int> ans(n+1,1);
//         int maxi=1;
//       //  cout<<ans.begin();
//         for(int i=1;i<n;i++)
//         {
           
//             for(int j=0;j<i;j++)
//             {
//                 if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1])
//                     ans[i]=max(ans[i], 1+ans[j]);
//             }
//             maxi=max(maxi,ans[i]);
    
//         }
        
//         return maxi;
 
        //2nd method
        vector<int> lis;
        for(int i=0;i<n;i++)
        {
            int ele= envelopes[i][1];
            int idx= lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            
            if(idx==lis.size()) lis.push_back(ele);
            else
                lis[idx]=ele;
        }
        return lis.size();
        
    }
};