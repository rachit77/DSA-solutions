class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        
        for(int i=0;i<n+1;i++)
        {
            v[i]=__builtin_popcount(i);
        }
        return v;
        
    }
};