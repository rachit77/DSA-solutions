class Solution {
public:
    int find(int n)
    {
        if(n==0) return 0;
        if(n==1)  return 1;
        return find(n-1)+ find(n-2);
    }
    int fib(int n) {
        
        return find(n);
    }
};