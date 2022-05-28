class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st,st2;
        string temp="";
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ' && temp.length()>0)
            {
               st.push(temp);
                temp="";
            }
            
            else
            {
                if(s[i]!=' ')
                temp=temp+s[i];
            }
        }
        
        if(temp.length()>0)
        st.push(temp);
        
        string ans="";
        
        if(!st.empty())
        {
           ans=st.top();
             st.pop();
        }
        
        while(!st.empty())
        {
            ans=ans+" "+st.top();
            st.pop();
        }
    
        return ans;
    }
};