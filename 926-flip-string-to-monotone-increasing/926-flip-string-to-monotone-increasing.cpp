class Solution {
public:
    int find_cost(int i, string s)
    {
        //count 1's left of i
        // count 0's right of i(inclusive)
        
        int l=0,r=0;
        for(int t=0;t<s.length();t++)
        {
            if(t<i)
            {
               if(s[t]=='1') l++; 
            }
            else
            {
                if(s[t]=='0') r++;
            }
        }
        return l+r;
    }
    
    int minFlipsMonoIncr(string s) {
      
        int n=s.length();
        
        int l=0,r= find_cost(0,s);  //all numst to 1
        int ans=r;

        for(int i=0;i<n;i++) // change everything to the left of i(including) to 0
        {
            if(s[i]=='0')
                r--;
            else
                l++;
            ans = min(ans,l+r);
        }
        
        return ans;
    }
};