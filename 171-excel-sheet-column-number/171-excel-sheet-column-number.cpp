class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int len=columnTitle.length();
        int ans=0,k=1;
        
        for(int i=len-1; i>=0;i--)
        {
            ans=ans+ (int(columnTitle[i]) -64) *k;
            if(i!=0)
            k=k*26;
        }
        
        return ans;
        
    }
};