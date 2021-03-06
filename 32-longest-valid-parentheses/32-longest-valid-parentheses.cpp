class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.length(),cnt=0;
        
        stack<pair<char,int>> st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({s[i],0});
            }
            
            else  //not empty
            {
                if(s[i]=='(')
                {
                    st.push({s[i],0});
                }
                else //s[i]= )
                {
                    if(st.top().first==')')
                    {
                        st.push({s[i],0});
                    }
                    else  // st.top=='('
                    {
                        pair<char,int> temp=st.top();
                        st.pop();
                        
                        if(!st.empty())
                        {
                            st.top().second+=2;
                            st.top().second+=temp.second;
                        }
                        else
                            cnt=cnt+2+temp.second;
                    }
                }
            }
        }
        
        int ans=cnt;
        while(!st.empty()){
            ans=max(ans, st.top().second);
            st.pop();
        }
        return ans;
        
    }
};