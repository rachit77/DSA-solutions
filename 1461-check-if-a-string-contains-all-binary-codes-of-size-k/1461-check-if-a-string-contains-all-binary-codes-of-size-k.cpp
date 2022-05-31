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
        
        //unordered_set<string> st;
        unordered_map<string,int> st;
        
        for(int i=0;i<n;i++)
        {
            if(i+k<=n)
            {
               string temp= s.substr(i,k);
               // st.insert(temp);
                st[temp]=1;
            }
            else break;
            
        }
        
        // int count=0;
        // for(auto i:st)
        //     count++;
            
        if(num== st.size())
            return true;
       
        return false;
        
    }
};