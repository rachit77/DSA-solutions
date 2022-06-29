class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& b, vector<int>& w) {
        
        //make a vector consisting of largest size of box that can be pushed there
        vector<int> v(w.size());
        
        //from left side
        int temp=INT_MAX;
        
        for(int i=0;i<w.size();i++)
        {
            v[i]=temp;
            if(w[i]<temp)
                temp=w[i];
        }
        
        //from right side
        temp=INT_MAX;
        for(int i=w.size()-1;i>=0;i--)
        {
            v[i]=min(w[i], max(v[i],temp));
            
            if(w[i]<temp)
                temp=w[i];
        } 
        
        sort(b.begin(),b.end(),greater<int>());
        sort(v.begin(), v.end(),greater<int>());
        
        int cnt=0;
        int i=0,j=0;
        
        while(i<b.size() && j<v.size())
        {
            if(b[i]<=v[j])
            {
                i++;
                j++;
                cnt++;
            }
            else
                i++;
        }
        
        return cnt;
        
    }
};