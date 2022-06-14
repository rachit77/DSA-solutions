class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans=0;
        
        int a=0,b=0;
        int n=text.length();
        
     if(pattern[0]!=pattern[1]){  
        for(int i=n-1;i>=0;i--)
        {
            if(text[i]==pattern[1])
               b++;
            
            if(text[i]==pattern[0])
            {
                a++;
                ans= ans+ b;
            }
        }
    }
        else
        {
           for(int i=n-1;i>=0;i--)
           {
              if(text[i]==pattern[1])
              {
                  ans=ans+a;
                  a++;
              }
           }
            
            
        }
        
        return (a>b)?ans+a:ans+b;
        
    }
};