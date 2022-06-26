class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto it:s)
            freq[it-'a']++;
        
        int count=0;
        
        unordered_set<int> st;
       
        for(int i=0;i<26;i++)
        {
            while(freq[i] && st.find(freq[i])!=st.end())
            {
                freq[i]--;
                count++;
            }
            st.insert(freq[i]);
        }
        
        
      
        return count;
    }
};