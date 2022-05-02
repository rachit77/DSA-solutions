class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st;
        
        int i;
        
        for(i=0;i<s.length();i++)
        {
            if(s[i]!='#')
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
        }
        
        s="";
        while(!st.empty())
        {
            char temp= st.top();
            s= temp+ s;
            st.pop();
        }
           
        
        
        for(i=0;i<t.length();i++)
        {
            if(t[i]!='#')
            {
                st.push(t[i]);
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
        }
        
        t="";
        while(!st.empty())
        {
            char temp= st.top();
            t= temp+ t;
            st.pop();
        }
        
        return (s==t)?1:0;
        
    }
};