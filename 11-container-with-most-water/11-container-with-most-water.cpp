class Solution {
public:
    int maxArea(vector<int>& height) {
       int i,j,n=height.size();
        int ans=0;

// method-1 brute force (tle)     
//         for(i=0;i<n;i++)
//         {
//             for(j=i+1;j<n;j++)
//             {
//                 int h=min(height[i],height[j]);
//                 int temp=h*(j-i);
                
//                 ans=max(ans,temp);
//             }
//         }       
//         return ans;
        
 // method-2 gredy approach
        int l=0,r=n-1,h=0;
        
        while(l<r)
        {
            int mi=min(height[l],height[r]);
            
            if(mi>h){
                h=mi;
            int area=h*(r-l);
            
            ans=max(ans,area);
            }
            if(height[l]<=height[r])
                l++;
            else
                r--;
        }
        return ans;
        
    }
};