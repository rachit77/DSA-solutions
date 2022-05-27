class Solution {
public:
//     void find(int id, vector<string> &ans, string &s)
//     {
// //         //base case
//         if(id==s.length())
//         {
//             ans.push_back(s);
//             return;
//         }
        
// //         // recursion condition
//         for(int i=id;i<s.size();i++)
//         {
//             swap(s[id],s[i]);
//             find(id+1,ans,s);
//             swap(s[id],s[i]);
//         }
        
//         return;
//     }
    
//     string getPermutation(int n, int k) {
        
//         vector<string> ans;
//         string s;
//         for(int i=1;i<=n;i++)
//         {
//             s.push_back(i+'0');
//             //s.emplace_back(i+'0');
//         }
//         cout<<s<<endl;
        
//         find(0,ans,s);
//         sort(ans.begin(), ans.end());
        
//         return ans[k-1];
//     }
    
    
    string getPermutation(int n, int k){
        
        int fact=1;
        string ans="";
        
        vector<int> num;
        k--;
        for(int i=1;i<n;i++)
        {
            num.push_back(i);
            fact*=i;
        }
        num.push_back(n);
        
        while(true)
        {
            char temp='0'+ num[k/fact];
            ans=ans + temp;
            num.erase(num.begin() + k/fact);
            
            if(num.size()==0) break;
            
            k=k%fact;
            fact=fact/num.size();
        }
        return ans;
    }
};