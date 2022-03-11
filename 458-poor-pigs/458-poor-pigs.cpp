class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int d=minutesToTest/minutesToDie;
        
        if(minutesToTest% minutesToDie!=0)
            d++;
        
        d++;
        
        int pigs=0;
        
        //int temp=Math.pow(d,pigs);
        
         int k=1;
        
        while(buckets > k) {
            pigs++;
            k=k*d;
        }
        
        return pigs;
        
    }
};