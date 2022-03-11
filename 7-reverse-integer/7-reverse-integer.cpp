class Solution {
public:
    int reverse(int x) {
        
        long int num=0;
        int flag=0;
        
        
       long xi=x;
        
        
        if(xi<0)
        {
            xi= xi* -1;
            flag=1;
            
        }
           // cout<<xi<<endl;
        
        while(xi)
        {
            long int rem =xi%10;
            xi=xi/10;
            
            //cout<<rem<<endl;
            
            num=num*10 +rem;
        }
        
        //cout<<num<<endl;
        
        if(flag==1)
            num=num * -1;
        
       // cout<<num<<endl;
        
        return (num>INT_MAX || num<=INT_MIN)?0:num;
        
    }
};