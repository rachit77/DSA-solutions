class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
vector<pair<int,int>> vis(256, make_pair(0,-1)); //pair{freq, index}
        int ans=0,cur=0,idx=-1;
        
        for(int i=0;i<s.length();i++)
        {
            int num=int(s[i]);
            
            if(vis[s[i]].first==1 && vis[num].second > idx) 
            {
                ans= max(ans,cur);
                idx=vis[num].second;
                cur=i-vis[num].second;
            }
            else   //not visted
                cur++;
             
            vis[num].first=1;
            vis[num].second=i;
        }
        
        ans=max(ans,cur);
        return ans;
    }
};