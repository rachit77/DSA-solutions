class Solution {
public:
//     bool check(string s1, string s2)
//     {
//         int x=s1.length(),y =s2.length();
//         int i=0,j=0;
        
//         while(i<x && j<y)
//         {
//           if(s1[i]==s2[j])   return false;
            
//             else if(s1[i]>s2[j]) j++;
//             else
//                 i++;
              
//         }
        
//         return true;
//     }
    
//     int maxProduct(vector<string>& words) {
        
//         for(int i=0;i<words.size();i++)
//             sort(words[i].begin(),words[i].end());
        
//         int ans=0,n=words.size();
        
//         for(int i=0;i<n-1;i++)
//         {
//             int fl=words[i].length();
//             int k=0;
            
//             for(int j=i+1;j<n;j++)
//             {
//                 int sl=words[j].length();
                
//                if(k<sl && check(words[i], words[j]))
//                {
                   
//                    ans=max(ans,fl*sl);
//                    //cout<<words[i]<<" "<<words[j]<<endl;
//                   // cout<<i<<" "<<j<<" "<<ans<<endl;
//                    k=sl;
//                }
//             }
//         }
        
//         return ans;
        
//     }
    
    
    // method-2 bit masking 
    int maxProduct(vector<string>& words) {
        int n=words.size();
        
        vector<int> mask(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(auto x: words[i])
            {
                mask[i]= mask[i] | (1<< (x-'a'));
            }
        }
        
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((mask[i] & mask[j]) ==0)
                {
                    int prod=words[i].length() * words[j].length();
                    ans= max(ans, prod);
                }
            }
        }
        
        return ans;
    }
};