class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> s;
        
        int i=0,j=0,n,m;
        
        n=pushed.size();
        m=popped.size();
        
        if(n!=m) return false;
        
        while(i<n)
        {
            if(s.empty()==true || s.top()!=popped[j])
            {
                s.push(pushed[i]);
                
            }
           
            
            while(!s.empty() && s.top()==popped[j]) {
                    //s.top ==popper[j]
                    s.pop();
                   
                    j++;
                    
                }
            i++;
            
            
            }
        
        while(j<n && !s.empty()) {
            if(s.top()==popped[j]) {
                
                s.pop();
            }
            
            j++;
                
        }
        
        return (s.empty())?true:false;
            
            
        
    }
};