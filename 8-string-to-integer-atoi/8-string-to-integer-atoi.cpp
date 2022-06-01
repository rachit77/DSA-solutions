class Solution {
public:
    int myAtoi(string s) {
        
        long ans=0;
        int t=0,i,n=s.length(),flag=1;
        
        while(t<n && s[t]==' ')
            t++;
        
        if(t<n && s[t]=='-')
        {
            flag=-1;
            t++;
        }
        else if(t<n && s[t]=='+')  t++;
       
        
        for(i=t;i<n;i++)
        {
           int temp=s[i]-48;
            if(temp>=0 && temp<=9)
            {
               ans=ans*10 + temp; 
               if(ans>=INT_MAX) break;
            }
            else break;
        }
        
        if(ans>INT_MAX)
            return flag==1?INT_MAX:INT_MIN;
    
 
        return (int)ans * flag;
        
    }
};