class Solution {
public:
    int strStr(string str, string pat) {
        
        int i,j,n=str.length(),m=pat.length();
    int ans;
    for(i=0;i<n;i++)
    {
        int t=i;
      if(str[t]==pat[0])
      {
          int cnt=0;
          while(t<n && cnt<m && str[t]==pat[cnt])
          {
              cnt++;
              t++;
          }
          if(cnt==m)
          {
              return i;
          }
      }
        
    }
    return -1;
        
    }
};