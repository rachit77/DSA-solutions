class Solution {
public:
    int minPartitions(string n) {
        
        int ans=0,flag=1;
        for(auto it:n)
        {
            if(it-'0'!=0) flag=0;
            ans= max(ans,(it-'0'));
        }
        
        //if(flag==1) return 1;
        return ans;
    }
};