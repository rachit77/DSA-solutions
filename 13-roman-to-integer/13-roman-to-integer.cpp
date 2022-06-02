class Solution {
public:
    int romanToInt(string s) {
        
        int i,n=s.length();
        
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        int ans=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(i!=0 && m[s[i-1]] < m[s[i]])
            {
                ans= ans+ -m[s[i-1]] +m[s[i]];
                i--;
            }
            else
            {
                ans+=m[s[i]];
            }
            //cout<<i<<" "<<ans<<endl;
        }
        return ans;
        
    }
};