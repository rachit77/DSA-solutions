class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        // uint32_t ans=0;
        // for(int i=0;i<32;i++)
        // {
        //     if((n & (1<<i)))
        //     {
        //         ans=ans+ 1<<(31-i);
        //     } 
        // }
        // return ans;
        
        
        uint32_t res = 0;
        for (int i = 0; i < 31; i++) {
            res = (n % 2) + res << 1;
            n >>= 1;
        }
        return res + n % 2;
    }
};