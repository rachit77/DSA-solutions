// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int> a, pair<int,int> b)
    {
        if(a.first == b.first) return a.second<b.second;
        return a.first<b.first;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
    
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        v.push_back({start[i], end[i]});
        
        sort(v.begin(), v.end(), comp);
        
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
                st.push(v[i]);
                
            else
            {
                 pair<int,int> temp=st.top();
                
                if(v[i].second < temp.second)
                {
                while(!st.empty() and v[i].second< st.top().second)
                {
                    st.pop();
                }
                    st.push(v[i]);
                }
                
                if(v[i].second > temp.second && v[i].first> temp.second) 
                {
                    st.push(v[i]);
                }
                
                
                
                
            }
        }
        
        return st.size();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends