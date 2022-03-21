class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> ans;
        
        vector<int> rec(26,-1);
        int i,n;
        n=s.length();
        
        for(i=0;i<n;i++) 
          rec[s[i]-'a']=max(i,rec[s[i]-'a']);
         
        int cur_len=0,br=-1;
        
        
        for(i=0;i<n;i++) {
            
            if(br==-1)
                br=rec[s[i]-'a'];
                
            else 
                br=max(br,rec[s[i]-'a']);
                
              cur_len++;  
                if(br==i)
                {
                    if(cur_len)
                    ans.push_back(cur_len);
                    cur_len=0;
                    br=-1;
                }
        }
        
        if(cur_len)
            ans.push_back(cur_len);
    
        return ans;
        
    }
};