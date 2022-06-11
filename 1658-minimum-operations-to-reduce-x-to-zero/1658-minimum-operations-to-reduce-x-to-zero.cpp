class Solution {
public:
    //method-1 recursion(TLE) and memoization(memory limit exceed)
//    int find(int first, int last, vector<int> &nums,int x,vector<vector<vector<int>>> dp)
//     {       
//         if(x==0) 
//             return 0;    
       
//         if(x<0 || last<first) 
//             return -1;
       
//        if(dp[first][last][x]!=-2) return dp[first][last][x];
        
//         int a= find(first+1, last, nums, x-nums[first],dp);
//         int b= find(first, last-1, nums,x-nums[last],dp);
       
//        if(a==-1 && b==-1) return dp[first][last][x]= -1;
      
//        int temp;
//         if(a==-1) temp=b+1;
//         else if(b==-1) temp= a+1;
//         else
//            temp= 1+min(a,b);
       
//        return dp[first][last][x]=temp;
//     }
    
//     int minOperations(vector<int>& nums, int x) {
//         int n=nums.size();
        
//         //create a 3-d vector dp first, last, sum
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(x+1,-2)));
//         int k= find(0,n-1,nums,x,dp);
//         return k;
//     }
    
    
    //method-2 memoization with better hashing technique (TLE)
//     int find(int l, int r, int x, vector<int> &nums, int count,unordered_map<string,int> &mp)
//     {
//         if(x==0)
//             return count;
        
//         if(x<0 || l>r) return 1e6;
        
//         string key= to_string(l)+"*"+to_string(r)+"*"+to_string(x);
        
//         if(mp[key]!=0) return mp[key];
        
//         int a= find(l+1,r,x-nums[l],nums,count+1,mp);
//         int b= find(l,r-1,x-nums[r],nums,count+1,mp);
        
//         return mp[key]=min(a,b);
//     }
//     int minOperations(vector<int>& nums, int x) {
//         int n=nums.size();
//         int count=0;
//         unordered_map<string,int> mp;
//         count=find(0,n-1,x,nums,0,mp);
        
//         return (count>=1e6)?-1:count;
//     }
    
    //method-3 prefix sum and map
//     int minOperations(vector<int>& nums, int x) {
        
//         int n=nums.size();
//         unordered_map<int,int> mp;
        
//         int sum=0;
//         for(int i=0;i<n;i++)
//         {
//             sum+=nums[i];
//             mp[sum]=i;
//         }
//         if(x>sum) return -1;
//         mp[0]=0;
        
//         sum=sum-x;
//         //cout<<sum<<endl;
        
//         int val=0,longest=0;
        
//         for(int i=0;i<n;i++)
//         {
//             val+=nums[i];
//             int find=val-sum;
            
//             if(mp.count(find)) //key is in map
//             {
//                // cout<<i<<endl;
//                 if(find==0) longest=max(longest,i+1);
//                 else
//                 longest=max(longest,i-mp[find]);
//             }
//         }
        
//         if(longest==0)
//         {
//             if(sum==0) return n;
//             else return -1;
//         }
//         else
//         return n-longest;
//     }
    
    //method-4 prefix and suffix sum : brute force O(N^2) TLE
//     int minOperations(vector<int>& nums, int x) {
//         int n=nums.size();
        
//         int i,j,ans=INT_MAX;
//         vector<int> pre(n+1,0), suf(n+1,0);
        
//         //fill prefix sum vector
//         for(i=1;i<=n;i++)
//             pre[i]=pre[i-1]+nums[i-1];
        
//         //fill sufix sum vector
//         for(i=n-1;i>=0;i--)
//             suf[i]=suf[i+1]+nums[i];
        
//         for(i=0;i<=n;i++)
//         {
//             for(j=n;j>=i;j--)
//             {
//                 //cout<<i<<" "<<j<<" "<<pre[i]+suf[j]<<endl;
//                if(pre[i]+suf[j]==x)
//                {
//                    int temp=i+n-j;
//                    //cout<<temp<<endl;
//                    ans=min(ans,temp);
//                }
//             }
//         }
//         cout<<ans<<endl;
//         return (ans==INT_MAX)?-1:ans;
//     }
    
    //method-5 prefix sum and binary search TC: NlogN
//     int minOperations(vector<int>& nums, int x)  {
//         int n=nums.size();
//         vector<int> pre(n+1,0);
        
//         for(int i=1;i<=n;i++)
//             pre[i]=pre[i-1] + nums[i-1];
        
//         int suf=0;
        
//         int ans=n+1; // stores no of element needed to make x
        
//         for(int i=n;i>=0;i--)
//         {
//             // apply binary search on prefix vector to find value corresponding to suffix
            
//             int st=0,en=i;
//             int find=x-suf;
            
//             if(find<0) break;
//             // find suf in pre vector of length n+1
//             while(st<=en)
//             {
//                int mid=st+(en-st)/2;
                
//                 if(pre[mid]==find)
//                 {
//                     ans=min(ans,n-i+mid);
//                     break;
//                 }
//                 else if(pre[mid]<find)
//                 {
//                    st=mid+1; 
//                 }
//                 else
//                 {
//                     en=mid-1;
//                 }
//             }
//             if(i!=0) suf+=nums[i-1];
//         }
        
//         return (ans==n+1)?-1:ans;
        
//     }
    
    //method-6 sliding window
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        
        for(auto x: nums) sum+=x;
        
        sum=sum-x;
        int i=0,j=0;
        
        if(sum==0) return n;
        if(sum<0) return -1;
        
        int window_sum=0;
        int ans=-1;
        while(j<n)
        {
            window_sum+=nums[j];
            
            while(window_sum > sum)
            {
                window_sum-=nums[i];
                i++;
            }
            if(window_sum==sum)
            {
                ans=max(ans,j-i+1);
            }
            j++;
        }
        
        return (ans==-1)?-1:n-ans;
    }
};