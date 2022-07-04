class Solution {
public:
    int candy(vector<int>& ratings) {
        int i,n=ratings.size();
        vector<int> tot(n,1);
        
        //left iterations +ve slope
        for(i=1;i<n;i++)
        {
            if(ratings[i-1]<ratings[i])
            {
                tot[i]=tot[i-1]+1;
            }
        }
        
        //right iteratins -ve slope
        for(i=n-2;i>=0;i--)
        {
            if(ratings[i+1]<ratings[i])
            {
                int temp=tot[i+1]+1;
                tot[i]=max(tot[i],temp);
            }
        }
        
        int ans=0;
        for(auto it:tot)
            ans+=it;
        
        return ans;
    }
};