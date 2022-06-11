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
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        unordered_map<int,int> mp;
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mp[sum]=i;
        }
        if(x>sum) return -1;
        mp[0]=0;
        
        sum=sum-x;
        //cout<<sum<<endl;
        
        int val=0,longest=0;
        
        for(int i=0;i<n;i++)
        {
            val+=nums[i];
            int find=val-sum;
            
            if(mp.count(find)) //key is in map
            {
               // cout<<i<<endl;
                if(find==0) longest=max(longest,i+1);
                else
                longest=max(longest,i-mp[find]);
            }
        }
        
        if(longest==0)
        {
            if(sum==0) return n;
            else return -1;
        }
        else
        return n-longest;
    }
};