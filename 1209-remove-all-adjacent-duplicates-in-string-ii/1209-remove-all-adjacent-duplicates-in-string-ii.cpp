class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        
        int n = s.size();
        if(n<k) return s;
        
        for(int i=0;i<s.length();i++)
        {
            if(st.empty() || st.top().first != s[i])
                st.push({s[i],1});
            
            else 
            {
                    st.top().second++;
                    if(st.top().second ==k) st.pop();

            }
        }
        
    
        string ans="";
       
        while(!st.empty())
        {
            auto cur = st.top();
            st.pop();
            
        while(cur.second--)
        {
            ans.push_back(cur.first);
            //ans = ans+ cur.first;
        }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;


        
    }
};