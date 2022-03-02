class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int sl,tl;
        sl=s.length();
        tl=t.length();
        
        int ans=0,i=0,j=0;
        
        
        while(i<sl && j<tl)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
                ans++;
            }
            else
            {
                j++;
            }
        }
        
        if(ans==sl)
            return true;
        else
            return false;
        
        
    }
};