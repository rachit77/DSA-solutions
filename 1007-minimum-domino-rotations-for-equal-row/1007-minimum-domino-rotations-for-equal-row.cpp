class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int t=0,b=0,i;
        vector<int> rec(7,0);
        
        int mx=0;
        int n=tops.size();
        
        for(i=0;i<n;i++) {
            if(tops[i]==bottoms[i])
            {
                rec[tops[i]]++;
            }
            else {
            rec[tops[i]]++;
            rec[bottoms[i]]++;
            }
        }
        
        int num;
        for(i=1;i<7;i++)
        {
            if(rec[i]>mx)
            {
                mx=rec[i];
                num=i;
            }
        }
        
        if(mx<n)
            return -1;
        
        int ans1=0,ans2=0;
        
        for(i=0;i<n;i++)
        {
           if(tops[i]!=num) ans1++;
            
           if(bottoms[i]!=num) ans2++;
        }
        
        //cout<<num<<endl;
        return min(ans1,ans2);
        
    }
};