class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
    
        int sign =(dividend>0 ^ divisor>0)?0:1;
      
        unsigned int ans=0;
        
        unsigned int a=abs(dividend);
        unsigned int b=abs(divisor);
        
         if(b>a) return 0;
        

        while(a>=b){
            int k=0;  
            while(a > (b<<k))
                k++;
            
            if(k) k--;
            ans=ans+ (1<<k);
            a=a-(b<<k);
            
        }  
        // while(a >= b){  // while dividend is greater than or equal to divisor
        //     short q = 0;
        //     while(a > (b<<(q+1)))
        //         q++;
        //     ans += (1<<q);  // add the power of 2 found to the answer
        //     a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
        // }
        
        
        
        
         if(ans>INT_MAX)
        {
           return sign==1 ? INT_MAX:INT_MIN;
        }    
        return sign ? ans : -ans;
      
    }
};