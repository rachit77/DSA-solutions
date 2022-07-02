class Solution {
public:
    int MOD=1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int max_w=horizontalCuts[0],max_h=verticalCuts[0];
        
        int i;
        for(i=0;i<horizontalCuts.size()-1;i++)
        {
            max_w=max(max_w,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        max_w=max(max_w, h-horizontalCuts[horizontalCuts.size()-1]);
        

        for(i=0;i<verticalCuts.size()-1;i++)
        {
            max_h=max(max_h,verticalCuts[i+1]-verticalCuts[i]);
        }
        max_h=max(max_h, w-verticalCuts[verticalCuts.size()-1]);
        

        long long ans=(((long)max_w % MOD)*(max_h % MOD))%MOD;
        return ans;
    }
};