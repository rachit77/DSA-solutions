class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
       
        
        //method-1 queries*N
        //method-2 sc:N*3 tc:queries
        
        int n=colors.size();
        int arr[n+1][4];
        
        //build the arr
        int one=-1,two=-1,three=-1;
        
        for(int i=0;i<n;i++)
        {
            //update one,two,three
            if(colors[i]==1) one=i;
            else if(colors[i]==2) two=i;
            else three=i;
            
            //update the arr
            if(one==-1) arr[i][0]=-1;
            else arr[i][0]=abs(one-i);
            
            if(two==-1) arr[i][1]=-1;
            else arr[i][1]=abs(two-i);
            
            if(three==-1) arr[i][2]=-1;
            else arr[i][2]=abs(three-i);    
        }
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<3;j++)
//                 cout<<arr[i][j]<<" ";
            
//             cout<<endl;
//         }
        
        
        one=-1,two=-1,three=-1;
        
        for(int i=n-1;i>=0;i--)
        {
            //update the one two three
            if(colors[i]==1) one=i;
            else if(colors[i]==2) two=i;
            else three=i;
            
            // cal the dis
            int dis_a=abs(one-i);
            int dis_b=abs(two-i);
            int dis_c=abs(three-i); 
            
            
            if(one!=-1) 
            {
                if(arr[i][0]==-1 ) arr[i][0]=dis_a;
                else
                arr[i][0]=min(arr[i][0],dis_a);
            }
            
            if(two!=-1)
            {
                if(arr[i][1]==-1 ) arr[i][1]=dis_b;
                else
                arr[i][1]=min(arr[i][1],dis_b);
            }
            
            if(three!=-1) 
            {
                if(arr[i][2]==-1 ) arr[i][2]=dis_c;
                else
                arr[i][2]=min(arr[i][2],dis_c); 
            }
            
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            ans.push_back(arr[ queries[i][0] ][ queries[i][1]-1 ] );
        }
        
        return ans;
    }
};