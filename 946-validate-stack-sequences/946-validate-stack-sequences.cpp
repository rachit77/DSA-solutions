class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
//         stack<int> s;
        
//         int i=0,j=0,n,m;
        
//         n=pushed.size();
//         m=popped.size();
        
//         if(n!=m) return false;
        
//         while(i<n)
//         {
//                 s.push(pushed[i]);
                
//             while(!s.empty() && s.top()==popped[j]) { //s.top ==popper[j] 
//                     s.pop();
//                     j++; 
//                 }
//             i++;
//         }
        
//         return (s.empty())?true:false;      
        
        
        //2nd approach with O(1) space complexity
        
        int i=0,j=0;
        
        for(auto x: pushed) {
            pushed[i]=x;
            
            while(i>=0 && pushed[i]==popped[j]) {
                j++;
                i--;
            }
            
             i++;
           
        }
        
        return i==0;
        
    }
};