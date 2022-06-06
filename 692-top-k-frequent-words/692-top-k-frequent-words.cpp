class Solution {
public:
    struct compare{
        bool operator()(pair<string,int> const& a, pair<string,int> const& b)
        {
            if(a.second == b.second)
            {
                //return string lexicographical
                int x=0,y=0;
                int n=a.first.length(),m=b.first.length();
                string s1=a.first, s2=b.first;
                int i=0;
                while(i<n ||i<m)
                {
                    if(i<n)
                    x=x+(s1[i]-'a'+1);
                    
                    if(i<m)
                    y=y+(s2[i]-'a'+1);
                    
                    i++;
                        
                    if(x>y) return true;
                    else if(x<y) return false;
                }
            }
            return b.second> a.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n=words.size();
        unordered_map<string,int> mp;
        
        for(auto i:words)
            mp[i]++;
        
        //make a max heap
        priority_queue< pair<string,int>, vector<pair<string,int>>, compare> pq;
        
        for(auto it:mp)
            pq.push({it.first,it.second});
        
        vector<string> ans;
        
        while(k--)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
        
    }
};