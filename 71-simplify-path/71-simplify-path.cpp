class Solution {
public:
    string simplifyPath(string path) {
        
//         stack<string> st;
//         int i=0;
        
//         //add slash at begining and end
//         path='/'+path+'/';
        
//         int n=path.length();
        
//         //add all elements in stack
//         while(i<n) {
            
//             if(path[i]=='/')
//             {
//                 i++;
//                 string temp;
//                 while(i<n and path[i]!='/')
//                 {
//                     temp=temp+path[i];
//                     i++;
//                 }
//                 if(!temp.empty()){
//                   st.push(temp);
//                 } 
                
//             }
//             else i++;
//         }
        
        
//         string ans;
        
//     while(!st.empty()) {
//             string tem=st.top();
//             st.pop();
        
//         // single period
//         if(tem==".")
//             continue;
//         else if(tem=="..") // double period
//         {
//             int back=1;
            
//             while(back!=0 and !st.empty())
//             {
//                     string ss=st.top();
//                     st.pop();
                
//                 if(ss==".")
//                 continue;
//                 else if(ss=="..")
//                     back++;
//                 else {
//                     back--;
//                 }
//             }
            
//         }
//         else {
//             ans=tem+'/'+ans;
//         }
//     }
        
        
    
//         if(!ans.empty() && ans[0]!='/')
//             ans='/'+ans;
        
//         if(ans.empty()) ans='/';
        
//         int len=ans.length();
        
//         if(len>1 && ans[len-1]=='/')
//             ans=ans.substr(0,len-1);
        
//         return ans;
        
        
//2nd method cleaner code
        
        stack<string> st;
        int i=1,n;
        
        path=path+'/';
        string temp;
        
        n=path.length();
        
        while(i<n)
        {
          if(path[i]=='/')
          {
             if(temp=="" || temp==".")
             {
                
             }
                
              else if(temp=="..")
              {
                  if(!st.empty())
                      st.pop();
              }
              else
              {
                  st.push(temp);
              }
              temp="";
          }
            else
                temp.push_back(path[i]);
                //temp=temp+path[i];
            
            i++;
              
        }
        
        
        //process the stack
//         string ans;
//         while(!st.empty()) {
//             ans="/"+st.top()+ans;
//             st.pop();
//         }
        
//         //check if string is empty
//         if(ans.empty())
//             ans="/";
        
//         return ans;
        
        
        
        
      string  ans="/";

stack<string>reversed_stack;

if(st.empty()){
    return ans;
}

while(!st.empty()){ // reverse the stack elements
    reversed_stack.push(st.top());
    st.pop();
}

while(!reversed_stack.empty()){
    ans+=reversed_stack.top()+"/";
    reversed_stack.pop();
}

return ans.substr(0,ans.length()-1);
        
    }
};