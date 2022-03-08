class Solution {
public:
    
    int solve(vector<int> &v)
    {
       int n=v.size();
        
        vector<int> prev(n,0),nex(n,0);
        
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and v[s.top()] >= v[i])
            {
                s.pop();
            }
            if(s.empty())
                prev[i]=-1;
            else
                prev[i]=s.top();
            
            s.push(i);
            
        }
        
        while(!s.empty())
            s.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() and v[s.top()] >= v[i])
            {
                s.pop();
            }
            if(s.empty())
                nex[i]=n;
            else
                nex[i]=s.top();
            
            s.push(i);
        }
        
        int area=0;
        
        for(int i=0;i<n;i++)
        {
            area= max(area,v[i]*(nex[i]-prev[i]-1));
        }
        
        return area;

    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int h=matrix.size();
        int w= matrix[0].size();
        
        vector<int> v(w,0);
        
        int area=0;
        
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(matrix[i][j]=='1')
                    v[j]+=1;
                else
                    v[j]=0;
            }
            
            area= max(area, solve(v));
            
            
        }
        
        return area;
        
    }
};