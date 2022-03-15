class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<pair<int,char>> st;
        
        int i,n=s.length();
        
        //st will contain index not to be included in string at the end 
        
        for(i=0;i<n;i++) {
            if(s[i]=='(' || s[i]==')')
            {
                if(!st.empty() && st.top().second == '(' && s[i]==')')
                {
                    st.pop();
                }
                else
                    st.push(make_pair(i,s[i]));
            }
        }
        
        // stack<pair<int,char>> k=st;
        // while(!k.empty())
        // {
        //     cout<<k.top().first<<" "<<k.top().second<<endl;
        //     k.pop();
        // }
        
        string ans;
        
        // reverse the stack st
        stack<pair<int, char>> st_rev;
        
        while(!st.empty())
        {
            st_rev.push(st.top());
            st.pop();
        }
        
        // stack<pair<int,char>> k=st_rev;
        // while(!k.empty())
        // {
        //     cout<<k.top().first<<" "<<k.top().second<<endl;
        //     k.pop();
        // }
        
        for(i=0;i<n;i++)
        {
            int temp;
            if(!st_rev.empty())
             temp= st_rev.top().first;
            
            //cout<<temp<<endl;
            
            if(i==temp) {
                st_rev.pop();
            }
            else
                ans+=s[i];
        }
        
        return ans;
        
    }
};