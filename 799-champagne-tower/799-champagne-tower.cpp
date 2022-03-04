class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<vector<double>> v(101, vector<double>(101,0.0));
        
        v[0][0]=poured;
        //cout<<v[0][0];
        int j;
        for(int i=0;i<query_row;i++)
        {
            for( j=0;j<=i;j++)
            {
                double k= (v[i][j]-1)/2.0;
                //cout<<k;
                
                if(k>0)
                {
                    v[i+1][j]+=k;
                    v[i+1][j+1]+=k;
                }
            }
           // cout<<i<<" "<<j<<" "<<v[i][j]<<endl;
        }
        
        //return min(1,v[query_row][query_glass]);
        
        if(v[query_row][query_glass]<1)
            return v[query_row][query_glass];
        else
            return 1;
        
    }
};