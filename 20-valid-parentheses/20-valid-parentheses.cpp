class Solution {
public:
    bool isValid(string s) {
       //solve using stacks
        
        stack<char> st;
        
        for(int i=0;i<s.length();i++)  {

            if(st.empty()==false){
                if(s[i]==')' && st.top()=='(')
                    st.pop();
                
               else if(s[i]=='}' && st.top()=='{')
                    st.pop();
                
               else if(s[i]==']' && st.top()=='[')
                    st.pop();
                
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);
        }
        
        if(st.empty())
            return true;
        else
            return false;
    }
};