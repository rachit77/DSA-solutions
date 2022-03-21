class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> ans;
        
        vector<pair<int,int>> rec(26,{-1,-1});
        int i,n;
        n=s.length();
        
        for(i=0;i<n;i++) {
            int temp=s[i]-'a';
            
        rec[temp].first=min(i,rec[temp].first);
            
        rec[temp].second=max(i,rec[temp].second);
        }
        
        
        int cur_len=0,br=-1;
        
        //cout<<rec[0].second<<endl;
        
        for(i=0;i<n;i++) {
            
            if(br==-1)
            {
                br=rec[s[i]-'a'].second;
                
            }
            else {
                if(i<br)
                {
                    br=max(br,rec[s[i]-'a'].second);
                    
                }
            }
                
              cur_len++;  
                if(br==i)
                {
                    if(cur_len)
                    ans.push_back(cur_len);
                    cur_len=0;
                    br=-1;
                }
            //}
            
            //cout<<i<<" "<<br<<" "<<cur_len<<endl;
            
            
            
        }
        
        if(cur_len)
            ans.push_back(cur_len);
        
        
        return ans;
        
    }
};