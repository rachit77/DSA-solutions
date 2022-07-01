class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int truckSize) {
        
        
        //knapsack
        
        //sort the boxType vector in desc order
        sort(b.begin(),b.end(),comp);
        
        int ans=0;
        
        for(auto it:b)
        {   
            if(truckSize==0) break;
            
            if(it[0]<=truckSize) //take all the boxes
            {
                truckSize-=it[0];
                ans= ans+ it[0]*it[1];
            }
            else //take truckSize number of boxes
            {
               ans= ans+ truckSize*it[1];
                truckSize=0;
            }
            
            //cout<<ans<<endl;
        }
        
        return ans;
    }
};