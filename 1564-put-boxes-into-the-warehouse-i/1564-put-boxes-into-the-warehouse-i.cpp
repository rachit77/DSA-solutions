class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& w) {
        
        //method-1
        //change the warehouse size
//         int temp=INT_MAX;
//         for(int i=0;i<w.size();i++)
//         {
//            w[i]=min(w[i],temp);
            
//             if(w[i]<temp)
//                 temp=w[i];
//         }
        
//         sort(boxes.begin(),boxes.end());
        
//         int cnt=0,i=w.size()-1,j=0;
        
//         while(i>=0 && j<boxes.size())
//         {
//            if(boxes[j]<=w[i]) // can fit the box here
//            {
//                i--;
//                j++;
//                cnt++;
//            }
//             else
//             {
//                 i--; // check pev warehouse
//             }
//         }
//         return cnt;
        
        //method-2 using o(1) space
        int cnt=0;
        int i=boxes.size()-1;
        sort(boxes.begin(),boxes.end());
        
        for(int room: w)
        {
            while(i>=0 && boxes[i]>room)
                i--;
            
            if(i==-1) return cnt;
            cnt++;
            i--;
        }
        
        return cnt;
    }
};