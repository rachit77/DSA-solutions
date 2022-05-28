class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st,st2;
        string temp="";
        //cout<<temp.length()<<endl;
        
        for(int i=0;i<s.length();i++)
        {
            //cout<<s[i];
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
        
        //cout<<st.size()<<endl;
        
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