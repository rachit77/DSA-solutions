class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int l=0,h=s.size()-1;
        
        while(l<h)
        {
            char temp=s[h];
            s[h]=s[l];
            s[l]=temp;
            
            l++;
            h--;
        }
        
     
        
    }
};