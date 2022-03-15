class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        
        //next smaller elemnet and prev smaller element
        vector<int> nex(n,0);
        vector<int> prev(n);
        
        stack<int> st;
        
        int i;
        
        //next smaller element
        for(i=0;i<n;i++) {
            
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                nex[st.top()]=i-1;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(!st.empty()) {
            nex[st.top()]=n-1;
            st.pop();
        }
        
        
       
        
        //test print nex vector
        
//         for(i=0;i<n;i++)
//         {
//             cout<<nex[i]<<endl;
//         }
        
        
        
        
        //previous smaller element
        for(i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]<arr[st.top()]) {
               
                prev[st.top()]=i+1;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(!st.empty())
        {
            prev[st.top()]=0;
            st.pop();
        }
        
        
        //test print nex vector
        // cout<<"------"<<endl;
        // for(i=0;i<n;i++)
        // {
        //     cout<<prev[i]<<endl;
        // }
        
        //now cal the sum of min in those sub arrays
        int ans=0;
        long long mod = 1e9 + 7;
        
        for(int i=0;i<n;i++){
            int left=i-prev[i]+1;
            
            int right=nex[i]-i+1;
            
            ans+= (arr[i]* ( (left*right)%mod) ) %mod;
            ans=ans%mod;
       
         }
        
        return ans;
        
        
    }
};