class Solution {
public:

    bool check(int l, int h, string s)
    {
        while(l<h)
        {
            if(s[l]!=s[h])
                return false;
            
            l++; h--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int l=0,h=s.length()-1;

        while(l<h) {
            if(s[l]!=s[h])
                return check(l+1,h,s) || check(l,h-1,s);
            
            l++;  
            h--;   
        }        
        return true;
        
    }
};