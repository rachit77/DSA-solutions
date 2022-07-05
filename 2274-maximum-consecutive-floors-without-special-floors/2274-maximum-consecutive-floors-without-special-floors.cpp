class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& sp) {
        
        sort(sp.begin(),sp.end());
        
        int n=sp.size();
        int max_floor=sp[0]-bottom;
        max_floor=max(max_floor, top-sp[n-1]);
        
        for(int i=1;i<n;i++)
        {
          int temp=sp[i]-sp[i-1]-1;
           max_floor=max(max_floor,temp);
        }
        
        return max_floor;
    }
};