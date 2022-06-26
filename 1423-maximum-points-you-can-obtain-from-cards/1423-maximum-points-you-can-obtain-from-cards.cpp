class Solution {
public:
    //method-1 TLE
//     int find(int l,int r,vector<int>& pt, int k,vector<vector<int>> &dp){
        
//         if(k==0|| r<0 || l>= pt.size()|| l>r)
//             return 0;
        
//         if(dp[l][r]!=-1) return dp[l][r];
        
//         int a=pt[l]+find(l+1,r,pt,k-1,dp);
//         int b=pt[r]+find(l,r-1,pt,k-1,dp);
//         return dp[l][r]=max(a,b);
        
//     }
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n=cardPoints.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         int ans=find(0,cardPoints.size()-1,cardPoints,k,dp);
//         cout<<ans;
//         return ans;
//     }
    
    //method-2 prefix sum and sliding window
    int maxScore(vector<int>& cardPoints, int k) {
        int n,sum=0;
        n=cardPoints.size();
        
        for(auto it:cardPoints)
            sum+=it;
        
        if(n<=k) return sum;
        
        //find n-k size sub array with min sum
        int sub_sum=INT_MAX;
        int cur_sum=0;
        int sub_len=n-k;
        int cur_len=0;
        
        for(int i=0;i<n;i++)
        {
            if(cur_len<sub_len){
               cur_sum+=cardPoints[i];
                cur_len++;
                continue;
            } 
            
            sub_sum=min(sub_sum,cur_sum);
            
            cur_sum=cur_sum-cardPoints[i-sub_len]+ cardPoints[i];
        }
        sub_sum=min(sub_sum,cur_sum);
       // cout<<sub_sum<<endl;
        return sum-sub_sum;
    }
};