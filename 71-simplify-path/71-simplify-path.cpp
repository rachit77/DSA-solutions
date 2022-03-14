class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        int i=0;
        
        //add slash at begining and end
        path='/'+path+'/';
        
        int n=path.length();
        while(i<n) {
            
            if(path[i]=='/')
            {
                i++;
                string temp;
                while(i<n and path[i]!='/')
                {
                    temp=temp+path[i];
                    i++;
                }
                //cout<<i<<" "<<temp<<endl;
                if(!temp.empty()){
                  st.push(temp);
                   //cout<<"tt"<<temp<<endl; 
                } 
                
            }
            else i++;
        }
        
        //cout<<"while over "<<endl;
        
        stack<string> k= st;
        //cout<<"vjnv"<<st.empty()<<endl;
        // while(!k.empty())
        // {
        //     cout<<k.top()<<endl;
        //         k.pop();
        // }
        
        //process the stack
        
        string ans;
        
    while(!st.empty()) {
            string tem=st.top();
            st.pop();
        
        // single period
        if(tem==".")
            continue;
        else if(tem=="..") // double period
        {
            int back=1;
            
            while(back!=0 and !st.empty())
            {
                    string ss=st.top();
                    st.pop();
                
                if(ss==".")
                continue;
                else if(ss=="..")
                    back++;
                else {
                    back--;
                    //ans=ss+'/'+ans;
                }
            }
            
        }
        else {
            ans=tem+'/'+ans;
        }
    }
        
        
    
        if(!ans.empty() && ans[0]!='/')
            ans='/'+ans;
        
        if(ans.empty()) ans='/';
        
        int len=ans.length();
        
        if(len>1 && ans[len-1]=='/')
            ans=ans.substr(0,len-1);
        
        return ans;
        
        
    }
};