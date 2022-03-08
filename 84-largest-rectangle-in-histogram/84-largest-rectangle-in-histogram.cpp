class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        
        vector<int> prev(n,0),nex(n,0);
        
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                prev[i]=-1;
                s.push(i);
            }
            else {
                prev[i]=s.top();
            
                 s.push(i);
            }
            
            
            
        }
        
        while(!s.empty())
            s.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                nex[i]=n;
                s.push(i);
            }
            else {
                nex[i]=s.top();
            
                 s.push(i);
            }
            
            
            
        }
        int area=0;
        for(int i=0;i<n;i++)
        {
            area=max(area, heights[i]*(nex[i]-prev[i]-1));
            
        }
            
        
        return area;
        
    }
};