class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& w) {
        
        //change the warehouse size
        int temp=INT_MAX;
        for(int i=0;i<w.size();i++)
        {
           w[i]=min(w[i],temp);
            
            if(w[i]<temp)
                temp=w[i];
        }
        
        sort(boxes.begin(),boxes.end());
        
        int cnt=0,i=w.size()-1,j=0;
        
        while(i>=0 && j<boxes.size())
        {
           if(boxes[j]<=w[i]) // can fit the box here
           {
               i--;
               j++;
               cnt++;
           }
            else
            {
                i--; // check pev warehouse
            }
        }
        return cnt;
    }
};