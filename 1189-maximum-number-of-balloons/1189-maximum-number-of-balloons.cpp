class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        vector<int> v(26,0);
        string s="balon";
        
        for(int i=0;i<text.length();i++)
        {
            v[ text[i] - 'a' ]+=1;
        }
        
        int ans=INT_MAX;
        v['l'-'a']=v['l'-'a']/2;
        v['o'-'a']=v['o'-'a']/2;
        
        for(int i=0;i<s.length();i++)
        {
            ans=min(ans,v[s[i]-'a']);
        }
         
        if(ans==INT_MAX)
            return 0;
        else
            return ans;
        
    }
};