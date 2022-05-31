class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        // can use set or map
        
        int n=s.length();
    
        // 2^k is the total num 
        int num=1;
        for(int i=1;i<=k;i++)
            num=2*num;
        
        
        if(n<=k) return false;
        
        set<string> st;
        
        for(int i=0;i<n;i++)
        {
            if(i+k<=n)
            {
               string temp= s.substr(i,k);
                st.insert(temp);
            }
            else break;
            
        }
            
        if(num== st.size())
            return true;
        else
        return false;
        
    }
};