class Solution {
public:
    int myAtoi(string s) {
        
        long long ans=0;
        int t=0,i,n=s.length(),flag=1;
        
        while(t<n && s[t]==' ')
            t++;
        
        if(t<n && s[t]=='-')
        {
            flag=-1;
            t++;
        }
        
        else if(t<n && s[t]=='+')
        {
            flag=1;
            t++;
        }
        
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
        cout<<ans<<endl;
        cout<<flag<<endl;
        
        if(ans>= INT_MAX && flag==1) return INT_MAX;
        else if(ans> INT_MAX && flag==-1) return INT_MIN;
        
        else return (int)ans * flag;
        
    }
};