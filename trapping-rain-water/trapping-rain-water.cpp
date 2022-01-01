class Solution {
public:
    int trap(vector<int>& height) {
        
       int  n=height.size();
        vector<int> l(n),r(n);
        //stack<int> s;
       
        int gr=0;
        
        // for left greater
        for(int i=0;i<n;i++)
        {
          if(height[i]<gr)
          {
              l[i]=gr;
          }
            else
            {
                l[i]=0;
                gr=height[i];
            }
        }
        
        //for right greater
        gr=0;
        for(int i=n-1;i>=0;i--)
        {
          if(height[i]<gr)
          {
              r[i]=gr;
          }
            else
            {
                r[i]=0;
                gr=height[i];
            }
        }
        
        
        // cal water
        int sum=0;
        for(int i=0;i<n;i++)
        {
          int temp= min(l[i],r[i]) - height[i];
            if(temp>0)
                sum+=temp;
        }
        
        return sum;
        
        
        
    }
};