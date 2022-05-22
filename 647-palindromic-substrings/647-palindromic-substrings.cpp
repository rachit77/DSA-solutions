class Solution {
public:
    //method-1 naive approach brute force
    
//     bool checkPalindrome(int i,int j, string s)
//     {
//         for(int t=0;t<=(j-i)/2;t++)
//         {
//             if(s[t+i]!=s[j-t]) return false;
//         }
//         return true;
//     }
    // int countSubstrings(string s) {
        
//         
//         int n=s.length(),ans=0;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i;j<n;j++)
//             {
//                 if(checkPalindrome(i,j,s)) ans++;
//             }
//         }
        
//         return ans;
    
    
    //method-2
    int countSubstrings(string s) {
    int n=s.length(),ans=0;
    
    for(int i=0;i<n;i++)   //for odd length
    {
        int l=i,r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {
            ans++;
            l--;
            r++;
        }
    }
    
    for(int i=0;i<n-1;i++) // for even length
    {
        int l=i,r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {
            l--;
            r++;
            ans++;
        }
    }
    
    return ans;
    
    }
};