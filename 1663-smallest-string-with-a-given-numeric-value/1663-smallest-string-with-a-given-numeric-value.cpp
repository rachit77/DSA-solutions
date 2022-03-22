class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans;
        int i;
        
        k=k-n;
        
        for(i=0;i<n;i++)
            ans+='a';
        
        for(i=n-1;i>=0;i--)
        {
            if(k==0)
                break;
            
            if(k>=25)
            {
                ans[i]='z';
                k-=25;
            }
            else {
                ans[i]=(char)(k+'a');
                k=0;
            }     
        }
        
        return ans;
        
    }
};