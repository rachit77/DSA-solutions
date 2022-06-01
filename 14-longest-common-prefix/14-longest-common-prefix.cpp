class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
//         int n=strs.size();
//         int cnt=0,flag=1;
//         for(int i=0;i<strs[0].length();i++)
//         {
//             char ch=strs[0][i];
//             if(flag){
//             for(int j=1;j<n;j++)
//             {
//                 if(strs[j].length() <= i ||  ch!= strs[j][i])
//                 {
//                     flag=0;
//                     break;
//                 }
//             }
//             if(flag)
//             cnt++;
//             }
//         }
        
//         return strs[0].substr(0,cnt);
        
        
        //method-2 tc: nlog(n)
        sort(strs.begin(),strs.end());
        string ans="";
        string a=strs[0];
        string b=strs[strs.size()-1];
        int cnt=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i] == b[i])
            {
                ans=ans+ a[i];
            }
            else break;
        }
        return ans;
    }
};