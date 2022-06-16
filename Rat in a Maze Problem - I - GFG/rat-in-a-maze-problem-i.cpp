// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int x, int y,string &s, vector<vector<int>> &m, int &n, vector<string> &ans,  vector<vector<int>> &vis)
    {
        if(x>=n || y>=n ||x<0 ||y<0 || m[x][y]==0 || vis[x][y]==1) return;
        
        if(x==n-1 && y==n-1)
        {
            ans.push_back(s);
            return;
        }
        vis[x][y]=1;
        s.push_back('D');
        solve(x+1,y,s,m,n,ans,vis);
        s.pop_back();
        
        s.push_back('R');
        solve(x,y+1,s,m,n,ans,vis);
        s.pop_back();
        
        s.push_back('U');
        solve(x-1,y,s,m,n,ans,vis);
        s.pop_back();
        
        s.push_back('L');
        solve(x,y-1,s,m,n,ans,vis);
        s.pop_back();
        
        vis[x][y]=0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
         vector < vector < int >> vis(n, vector < int > (n, 0));
        vector<string> ans;
        string s="";
        solve(0,0,s,m,n,ans,vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends