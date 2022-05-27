class Solution {
public:
    int numberOfSteps(int n) {
        int cnt=0;
        
        while(n)
        {
            if(n&1) //odd
             n--;
            else
                n/=2;
            cnt++;
        }
        return cnt;
        
    }
};