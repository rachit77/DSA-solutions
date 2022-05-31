class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int n=s.length();

        unordered_set<string> st;
        
        for(int i=0;i<=n-k;i++)
        {
               string temp= s.substr(i,k);
               st.insert(temp);
                
        }
        
        return (1<<k) == st.size();
            
    }
};