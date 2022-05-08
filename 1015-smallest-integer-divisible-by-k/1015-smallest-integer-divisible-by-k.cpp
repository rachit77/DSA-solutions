class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        
        int res = 1, rem = 1;
        
        while (rem % k) {
            rem = (rem * 10 + 1) % k;
            res++;
        }
        return res;
        
    }
};