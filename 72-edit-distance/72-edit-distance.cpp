class Solution {
public:
    int minDistance(string word1, string word2) {
        
        // find lcs of 2 strings
        //  
        
        int n,m;
        n=word1.length();
        m=word2.length();
        
        int arr[n+1][m+1];
        
        for(int i=0;i<n+1;i++)
            arr[i][0]=i;
        
        for(int i=0;i<m+1;i++)
            arr[0][i]=i;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                    arr[i][j]=arr[i-1][j-1] ;
                else
                {
                    int k=min(arr[i-1][j],arr[i][j-1]);
                    arr[i][j]=min(arr[i-1][j-1], k) +1;
                    

                }
            }
        }
        
       
        return arr[n][m];
    }
};