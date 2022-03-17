class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int ans=0,i,temp=0;
        
        stack<pair<char,int>> st;
        
        
        for(i=0;i<s.length();i++) {
            
                if(s[i]=='(')
                {
                   st.push({s[i],0}); 
                }
                else // s[i]==')'
                {
                    temp=max(2* st.top().second,1);
                    st.pop();
                    //now check if stack is empty or not
                    
                    if(st.empty()==true)
                    {
                        ans+=temp;
                        temp=0;
                    }
                    else {
                        st.top().second+=temp;
                    }
               
            }
        }
        
        return ans;
        
    }
};