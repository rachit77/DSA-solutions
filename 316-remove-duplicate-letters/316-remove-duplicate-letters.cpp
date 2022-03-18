class Solution {
public:
    string removeDuplicateLetters(string s) {
        
       //vector to store frequency of alphabet
        // vector to store the elements visited
        // stack
        
        
        vector<int> vis(26,0),freq(26,0);
        int i,n;
        n=s.length();
        
        for(i=0;i<n;i++)
            freq[s[i]-'a']++;
        
        stack<char> st;
        
        for(i=0;i<n;i++)
        {
            if(vis[s[i]-'a']==0){
            if(st.empty())
            {
                st.push(s[i]);
                vis[s[i]-'a']=1;
                
            }
                
            else {
                
            while(!st.empty() && s[i]<st.top() && freq[st.top()-'a']>0)                 {   
                    vis[st.top()-'a']=0; //mark it unvisited again
                //cout<<i<<" "<<st.top()<<" "<<freq[st.top()-'a']<<endl;
                    st.pop();
                   
                }
                
                st.push(s[i]);
                vis[s[i]-'a']=1;
                // freq[s[i]-'a']--;
             }
            }
            freq[s[i]-'a']--;
           
        }
        
        string ans;
        while(!st.empty())
        {
            ans=st.top() + ans;
            st.pop();
        }
        
        return ans;
        
    }
};