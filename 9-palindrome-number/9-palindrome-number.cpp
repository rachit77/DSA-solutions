class Solution {
public:
    bool isPalindrome(int x) {
        
        long long n=x;
        long long num=0;
        
        if(n<0)
        {
            n=n*(-1);
        }
        while(n)
        {
           int temp=n%10;
            num= num*10 +temp;
            n/=10;
        }
        
        if(num==x)
            return true;
        else 
            return false;
        
    }
};