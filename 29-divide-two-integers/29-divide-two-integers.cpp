class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign =(dividend>0 ^ divisor>0)?0:1;
      
        long int ans=0;
        
        long int a=abs(dividend);
        long int b=abs(divisor);
        
        // if(b>a) return 0;
        

        while(a>=b){
            int k=0;  
            while(a > (b<<k))
                k++;
            
            if(k) k--;
            ans=ans+ (1<<k);
            a=a-(b<<k);
            
        }  

         if(ans>INT_MAX)
        {
           return sign==1 ? INT_MAX:INT_MIN;
        }    
        return sign ? ans : -ans;
      
    }
};