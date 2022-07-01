class Solution {
public:
    
//     int find(string &s, vector<int> query)
//     {
//         int flag=0,cnt=0,temp=0;
        
//         for(int i=query[0];i<=query[1];i++)
//         {
//             if(s[i]=='|' && flag==1)
//             {
//                 cnt+=temp;
//                 temp=0;
//             }
            
//             if(s[i]=='|') flag=1;
            
//             if(flag && s[i]=='*')
//                 temp++;
//         }
        
//         return cnt;
//     }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int total_queries=queries.size();
        vector<int> ans;        
        
        int n=s.length();

       vector<int> stars(n,0);
        
        int temp=0;
        for(int i=0;i<n;i++)
        {
            stars[i]=temp;
            if(s[i]=='*') temp++;
        }
        
        vector<int> l(n),r(n);
        
        temp=-1;
        for(int i=0;i<n;i++)
        {
           if(s[i]=='|')
           {
               temp=i;
           }
            
            l[i]=temp;
        }
        
        temp=n;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='|')
            {
                temp=i;
            }
            
            r[i]=temp;
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int qLeft= queries[i][0];
            int qRight= queries[i][1];
            
            int l_id=r[qLeft];
            int r_id=l[qRight];
            
            if(l_id==n || r_id==-1 || l_id>r_id)
                ans.push_back(0);
            else
            {
                ans.push_back(stars[r_id]-stars[l_id]);
            }
        }
        
        return ans;
    }
};