class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int ans=0,i,temp=0;
        
        stack<pair<char,int>> st;
        
        // stack is empty to add the ans
        // int temp -> contains the value we made inside a bracket  //               // stack<pair<char,int>> st
        // 
        
        for(i=0;i<s.length();i++) {
            
            if(st.empty()==true)
            {
                st.push({s[i],0});
                ans+=temp;
                temp=0;
            }
            else {  //stack not empty
                if(s[i]=='(')
                {
                   st.push({s[i],0}); 
                }
                else // s[i]==')'
                {
                   if(st.top().second==0) 
                   {
                       temp=1;
                       st.pop();
                   }
                    else //st.top().second!=0
                    {
                        temp=2* st.top().second;
                        st.pop();
                    }
                    
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
        }
        
        return ans;
        
    }
};