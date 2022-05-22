class Solution {
public:
    bool checkPalindrome(int i,int j, string s)
    {
        for(int t=0;t<=(j-i)/2;t++)
        {
            if(s[t+i]!=s[j-t]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        
        //method-1 naive approach brute force
        int n=s.length(),ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(checkPalindrome(i,j,s)) ans++;
            }
        }
        
        return ans;
    }
};